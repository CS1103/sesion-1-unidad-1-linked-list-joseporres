//
// Created by Jose Adrian on 11/04/2020.
//

#ifndef INC_11_DE_ABRIL_F_H
#define INC_11_DE_ABRIL_F_H
#include <iostream>
#include <cassert>
#include<string>
#include <cctype>


using namespace std;

namespace utec
{
    struct  node_t {
        int value_ = 0;
        node_t* next_ = nullptr;
    };

    inline namespace  first{
        class linked_list_t{
        private:
            node_t* head_=nullptr;
            node_t* tail_ = nullptr;
            size_t size_ = 0;
        public:
            //constructores
            linked_list_t()= default;
            linked_list_t(const linked_list_t& other);
            linked_list_t&operator=(const linked_list_t& other);
            linked_list_t(linked_list_t&& other) noexcept;
            linked_list_t&operator=(linked_list_t&& other) noexcept;
            //destructores
            ~linked_list_t();

            //add
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index,int value);

            //remove
            void pop_front();
            void pop_back();
            void erase(size_t index);

            //traverse
            int& item(size_t index);
            node_t* p_item(size_t index) const;
            const int& item(size_t index)const;
            size_t size()const;



        };
    }
}
#endif //INC_11_DE_ABRIL_F_H

