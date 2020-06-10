#pragma once
#include "command.h"
#include <atomic>
#include <type_traits>
#include <memory>
#include <boost/shared_ptr.hpp>

namespace rk {

template<typename T>
class rk_shared_ptr;

template<typename _Tp, typename... _Args>
inline rk_shared_ptr<_Tp>
make_shared(_Args&&... __args)
{
    typedef typename std::remove_const<_Tp>::type _Tp_nc;
    return rk_shared_ptr<_Tp>(new _Tp_nc(std::forward<_Args>(__args)...));
}

template<typename T>
class ControlBlock{

public:
    explicit ControlBlock(T* p_NewPtr) noexcept
        : mDataPtr(p_NewPtr), m_refCount(1) { }

    void AddRef(){

        m_refCount.fetch_add(1, std::memory_order_relaxed);
    }
    void ReleaseRef(){

        m_refCount.fetch_sub(1, std::memory_order_acq_rel);
        if (m_refCount.load(std::memory_order_acquire) == 0){

            delete mDataPtr;
            delete this;
        }
    }
    long GetRefCount(){

        return m_refCount.load(std::memory_order_relaxed);
    }
private:
    std::atomic_int m_refCount;
    T* mDataPtr;
};

template<typename T>
class rk_shared_ptr{

public:
    using element_type = T;
    void swap(rk_shared_ptr<T>& p_Other) noexcept
    {
        std::swap(mData, p_Other.mData);
        std::swap(m_RefCount, p_Other.m_RefCount);
    }
    ~rk_shared_ptr(){

        if (m_RefCount){

            m_RefCount->ReleaseRef();
        }
    }

    // Default Ctor
    constexpr rk_shared_ptr() noexcept
        :mData(nullptr), m_RefCount(nullptr){

    }

    // Parametrized Ctor
    explicit rk_shared_ptr(element_type* p_newPointer) noexcept
        : mData(p_newPointer) {

        try{
            m_RefCount = new ControlBlock(p_newPointer);
        }
        catch(...){
            if (m_RefCount) delete m_RefCount;
            if (mData) delete mData;
        }
    }

    // Copy Ctro
    rk_shared_ptr(const rk_shared_ptr& p_Rhs) noexcept
        :mData(p_Rhs.mData), m_RefCount(p_Rhs.m_RefCount)
    {
    }
    // Move Ctor
    rk_shared_ptr(rk_shared_ptr&& p_Rhs) noexcept
        : mData(p_Rhs.mData)
    {
        m_RefCount = p_Rhs.m_RefCount;
        p_Rhs.mData = nullptr;
    }

    // Copy Assignment Operator
    rk_shared_ptr& operator=(rk_shared_ptr& p_Rhs) noexcept
    {
        mData = p_Rhs.mData;
        if (p_Rhs.m_RefCount){
            p_Rhs.m_RefCount->AddRef();
        }
        if (m_RefCount){
            m_RefCount->ReleaseRef();
        }
        m_RefCount = p_Rhs.m_RefCount;
        return *this;
    }
    long use_count() const noexcept
    {
        long v = (m_RefCount ? m_RefCount->GetRefCount() : 0);
        return v;
    }
    void reset() noexcept
    {
        rk_shared_ptr().swap(*this);
    }
    void reset(element_type* p_NewPointer)
    {
        assert(p_NewPointer != nullptr);
        rk_shared_ptr(p_NewPointer).swap(*this);
    }
    element_type& operator*() const noexcept
    {
        assert(mData != nullptr);
        return mData;
    }

    element_type* operator->() const noexcept
    {
        assert(mData != nullptr);
        return mData;
    }
    explicit operator bool() const
    {
        return (mData == nullptr ? false : true);
    }
private:
    element_type* mData;
    ControlBlock<element_type>* m_RefCount;
};
}
using namespace rk;

class smart_pointer: public Command{

    void execute(){

        struct A{
            A(int p_A){a = p_A;}
            ~A(){

                std::cout << "A's Destructor for a: " << a << std::endl;
            }
            int a;
        };
        rk_shared_ptr<A> p;
        rk_shared_ptr<A> p1 = rk::make_shared<A>(5);
        std::cout << "use count of p1: " << p1.use_count() << std::endl;
        p = p1;
        std::cout << "use count of p1 after assigning to \"p\": " << p1.use_count() << std::endl;
        p.reset(new A(7));
        std::cout << "use count of p1 after re-assigning \"p\": " << p1.use_count() << std::endl;
        p1.reset();
    }
};
