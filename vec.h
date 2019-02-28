//
// Created by Zver on 09.01.2018.
//

#ifndef LABASOLO4_VEC_H
#define LABASOLO4_VEC_H

#include <stdexcept>

namespace vec {

    template <class T>
    class vector_iterator {
    private:
        T* cur;

    public:
        vector_iterator() : cur(nullptr) {}
        explicit vector_iterator(T* obj) : cur(obj) {}

        T& operator * () const;
        T* operator -> () const;
        T& operator [] (int pos) const;
        vector_iterator& operator ++ ();
        vector_iterator operator ++(int);
        vector_iterator operator +(int t) const;
        vector_iterator operator -(int t) const;
        int operator == (const vector_iterator& cmp) const;
        int operator != (const vector_iterator& cmp) const;
    };


    template<class T>
    class const_vector_iterator { // const_vectIt
    private:
        const T* cur;

    public:
        const_vector_iterator() : cur(nullptr) {}
        explicit const_vector_iterator(T* obj) : cur(obj) {}

        const T& operator * () const;
        const T* operator -> () const;
        const T& operator [] (int pos) const;
        const_vector_iterator& operator ++ ();
        const_vector_iterator operator ++ (int);
        const_vector_iterator operator + (int t) const;
        const_vector_iterator operator - (int t) const;
        int operator == (const const_vector_iterator& cmp) const;
        int operator != (const const_vector_iterator& cmp) const;
    };


    template<class T>
    class vector {
    private:
        int maxSize_; // размер выделенной памяти
        int size_; // текущее
        static const int quota_ = 10; // увеличиваем maxSize_
        T* arr_;

    public:
        vector();
        void push_back(const T& value);
        void clear();
        int size() const;
        int max_size() const;

        bool empty() const;
        T& operator [] (int pos);
        const T& operator [] (int pos) const;
        vector(const vector&);
        vector& operator = (const vector&);

        friend class vector_iterator<T>;
        typedef class vector_iterator<T> iterator;

        friend class const_vector_iterator<T>;
        typedef class const_vector_iterator<T> const_iterator;

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        iterator  erase(iterator pos);
        ~vector() { delete[] arr_; }
    };


    /////////////////////////////////////////////////////////////////

    template<class T>
    T& vector_iterator<T>::operator * () const {
        if (!cur) {
            throw std::domain_error("Pointer to NULL");
        }
        return *cur;
    }


    template<class T>
    T* vector_iterator<T>::operator -> () const {
        return cur;
    }


    template<class T>
    T& vector_iterator<T>::operator [] (int pos) const {
        if (!cur) {
            throw std::domain_error("Pointer to NULL");
        }
        return *(cur + pos);
    }


    template<class T>
    vector_iterator<T>& vector_iterator<T>:: operator ++ () {
        ++cur;
        return (*this);
    }


    template<class T>
    vector_iterator<T> vector_iterator<T>:: operator ++(int) {
        vector_iterator<T> res(*this);
        ++cur;
        return res;
    }


    template<class T>
    vector_iterator<T> vector_iterator<T>::operator +(int t) const {
        return vector_iterator<T>(cur + t);
    }


    template<class T>
    vector_iterator<T> vector_iterator<T>::operator -(int t) const {
        return vector_iterator<T>(cur - t);
    }


    template<class T>
    int vector_iterator<T>:: operator == (const vector_iterator<T>& cmp) const {
        return cur == cmp.cur;
    }


    template<class T>
    int vector_iterator<T>:: operator != (const vector_iterator<T>& cmp) const {
        return cur != cmp.cur;
    }

    /////////////////////////////////////////////////////////////////////////////

    template<class T>
    const T& const_vector_iterator<T>:: operator * () const {
        if (!cur) {
            throw std::domain_error("Pointer to NULL");
        }
        return *cur;
    }
    template<class T>
    const T* const_vector_iterator<T>::operator -> () const {
        return cur;
    }
    template<class T>
    const T& const_vector_iterator<T>::operator [] (int pos) const {
        if (!cur) {
            throw std::domain_error("Pointer to NULL");
        }
        return *(cur + pos);
    }
    template<class T>
    const_vector_iterator<T>& const_vector_iterator<T>::operator ++() {
        cur++;
        return(*this);
    }
    template<class T>
    const_vector_iterator<T> const_vector_iterator<T>::operator ++(int) {
        const_vector_iterator<T> res(*this); cur++;
        return res;
    }
    template<class T>
    int const_vector_iterator<T>:: operator == (const const_vector_iterator<T>& cmp) const {
        return cur == cmp.cur;
    }
    template<class T>
    int const_vector_iterator<T>:: operator != (const const_vector_iterator<T>& cmp) const {
        return cur != cmp.cur;
    }
    template<class T>
    const_vector_iterator<T> const_vector_iterator<T>::operator +(int t) const {
        return const_vector_iterator<T>(cur + t);
    }
    template<class T>
    const_vector_iterator<T> const_vector_iterator<T>::operator -(int t) const {
        return const_vector_iterator<T>(cur - t);
    }

    //////////////////////////////////////////////////////////////////////////////////

    template<class T>
    vector<T>::vector() {
        maxSize_ = 0;
        size_ = 0;
        arr_ = nullptr;
    }


    template<class T>
    void vector<T>::push_back(const T& value) {
        if (size_ == 0) {
            arr_ = new T[quota_];
            maxSize_ = quota_;
            arr_[size_++] = value;
            return;
        }
        if (size_ < maxSize_) {
            arr_[size_++] = value;
        }
        else {
            T* ptr = arr_;
            arr_ = new T[maxSize_ + quota_];
            maxSize_ += quota_;
            for (int i = 0; i < size_; ++i) {
                arr_[i] = ptr[i];
            }
            delete[] ptr;
            arr_[size_++] = value;
        }
        return;
    }


    template<class T>
    void vector<T>::clear() {
        maxSize_ = 0;
        size_ = 0;
        delete[] arr_;
        arr_ = nullptr;
    }


    template<class T>
    int vector<T>::size() const {
        return size_;
    }


    template<class T>
    int vector<T>::max_size() const {
        return maxSize_;
    }


    template<class T>
    bool vector<T>::empty() const {
        return size_ == 0;
    }


    template<class T>
    T& vector<T>::operator [] (int pos) {
        if (pos >= size_) {
            throw std::out_of_range("Illegal Index");
        }
        return arr_[pos];
    }


    template<class T>
    const T& vector<T>::operator [] (int pos) const {
        if (pos >= size_) {
            throw std::out_of_range("Illegal Index");
        }
        return arr_[pos];
    }


    template<class T>   //  vector<T>::iterator
    vector_iterator<T> vector<T>::begin() {
        return vector_iterator<T>(arr_);
    }


    template<class T>   //  vector<T>::iterator
    vector_iterator<T> vector<T>::end() {
        return iterator(arr_ + size_);
    }


    template<class T>   //  vector<T>::const_iterator
    const_vector_iterator<T> vector<T>::cend() const {
        return const_iterator(arr_ + size_);
    }


    template<class T>   //  vector<T>::const_iterator
    const_vector_iterator<T> vector<T>::cbegin() const {
        return const_iterator(arr_); // return vector<T>::const_iterator(arr_);
    }


    template<class T>   //  vector<T>::iterator
    class vector_iterator<T>  vector<T>::erase(iterator pos) {
        vector<T>::iterator prev(pos);
        if ((++pos) == this->end()) {
            --size_;
            return pos;
        }
        pos = prev;
        T* mas = &(*pos);
        while (++pos != end()) {
            *prev = *pos;
            prev = pos;
        }
        --size_;
        iterator res(mas);
        return res;
    }


    template<class T>
    vector<T>::vector(const vector<T>& obj) {
        size_ = obj.size_;
        maxSize_ = obj.maxSize_;
        arr_ = new T[maxSize_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = obj.arr_[i];
        }
    }


    template<class T>
    vector<T>& vector<T>::operator = (const vector<T>& obj) {
        if (this != &obj) {
            this->clear();
            size_ = obj.size_;
            maxSize_ = obj.maxSize_;
            arr_ = new T[maxSize_];
            for (int i = 0; i < size_; ++i) {
                arr_[i] = obj.arr_[i];
            }
        }
        return (*this);
    }



}

#endif //LABASOLO4_VEC_H
