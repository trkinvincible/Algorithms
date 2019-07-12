#ifndef ALTONOMY_H
#define ALTONOMY_H

#include "command.h"
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}



string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


std::map<int,int> backup;

SinglyLinkedListNode* condense(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *prev = head;
    SinglyLinkedListNode *current = head->next;
    while (current != NULL) {

      if (backup[current->data] > 1) {

        prev->next = current->next;
        delete current;
      } else {

        backup[current->data]++;
      }
      current = current->next;
    }

    return head;
}

class altonomy: public Command{

    void execute()
    {
        ofstream fout(getenv("OUTPUT_PATH"));

        SinglyLinkedList* head = new SinglyLinkedList();

        string head_count_temp("3 4 3 2 6 1 2 6");

        int head_count = stoi(ltrim(rtrim(head_count_temp)));

        for (int i = 0; i < head_count; i++) {
            string head_item_temp;
            getline(cin, head_item_temp);

            int head_item = stoi(ltrim(rtrim(head_item_temp)));

            head->insert_node(head_item);
        }

        SinglyLinkedListNode* result = condense(head->head);

        print_singly_linked_list(result, "\n", fout);
        fout << "\n";

        fout.close();
    }
};

#endif // ALTONOMY_H
