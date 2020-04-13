//
// Created by Jose Adrian on 11/04/2020.
//

#include "linked_list.h"
utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    size_= 1;
    auto actual = other.head_;
    head_ = new node_t{actual->value_,nullptr};
    tail_=head_;
    while (actual->next_)
    {
        actual=actual->next_;
        this->push_back(actual->value_);
    }

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if (other.size_ != 0)
    {
        size_ = 1;
        auto actual = other.head_;
        head_ = new node_t{ actual->value_, nullptr };
        tail_ = head_;

        size_t i = 1;
        while (i < other.size_)
        {
            actual = actual->next_;
            this->push_back(actual->value_);
            ++i;
        }
    }

    else
    {
        head_ = nullptr;
        tail_ = nullptr;

    }
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {

    size_ = move(other.size_);

    head_ = move(other.head_);

    tail_ = move(other.tail_);

    other.size_  = 0;

    delete other.head_;

    delete other.tail_;

    other.head_ = nullptr;

    other.tail_ = nullptr;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    auto actual = head_;

    while (actual != nullptr)
    {
        auto next = actual->next_;
        delete actual;
        actual = next;
    }
    size_ = move(other.size());
    head_ = move(other.head_);
    tail_ = move(other.tail_);
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    node_t *puntero;

    for (puntero = head_; head_; puntero = head_)
    {
        head_ = head_->next_;
        delete puntero;
    }
}

void utec::first::linked_list_t::push_front(int value) {
    head_ = new node_t{value,head_};
    if(tail_ == nullptr) tail_=head_;
    size_++;

}

void utec::first::linked_list_t::push_back(int value) {
    auto aux = new node_t{value, nullptr};
    if(head_ == nullptr){
        head_=tail_= aux;
        ++size_;
    }
    else {
        auto acutal = head_;
        size_t index = size_ - 1;
        while (index--)
            acutal = acutal->next_;
        acutal->next_ = aux;
        tail_ = aux;
        size_++;
    }
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if (head_ == tail_)
    {
        head_ = new node_t{ value, tail_ };
        if (tail_ == nullptr)
        {
            tail_ = head_;
        }
    }
    else
    {
        p_item(index - 1)->next_ = new node_t{ value, p_item(index) };

    }
    ++size_;
}


void utec::first::linked_list_t::pop_front() {
    if (head_ == tail_)
    {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    else
    {
        auto aux = head_->next_;
        delete head_;
        head_->next_ = nullptr;
        head_ = aux;
        --size_;
    }
}


void utec::first::linked_list_t::pop_back() {
    if(head_ == tail_)
    {
        delete tail_;
        head_ = tail_=nullptr;
    }
    else
    {
        delete tail_->next_;
        tail_->next_= nullptr;
        --size_;
    }

}

void utec::first::linked_list_t::erase(size_t index) {
    if (head_ == tail_)
    {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else
    {
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size_ - 1)
        {
            pop_back();
        }
        else
        {
            auto aux = p_item(index + 1);
            delete p_item(index);
            p_item(index - 1)->next_ = aux;
            --size_;
        }
    }
}


int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;

    while (index--)
    {
        actual = actual->next_;
    }

    return actual->value_;
}

utec::node_t *utec::first::linked_list_t::p_item(size_t index) const {
    auto actual = head_;

    while (index--)
    {
        actual = actual->next_;
    }

    return actual;
}


const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while (index--)
    {
        actual = actual->next_;
    }

    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}



