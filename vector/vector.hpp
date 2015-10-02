/* Copyright (c) 2015, Jakub Borowski */
#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <initializer_list>

/* TODO:
 * - void assing( InputIt first, IntputIt last );
 * - reference front();
 * - const_reference front() const;
 * - reference back();
 * - const_reference back() const;
 * - size_type max_size() const noexcept;
 * - void reserve( size_type new_cap );
 * - void shrink_to_fit();
 * - insert ();
 * - iterator erase( iterator pos );
 * - void pop_back();
 */

using std::begin;
using std::fill;
using std::end;
using std::copy;

/*!
 * A Vector class written as an excercise
 */
template<typename T>
class Vector {
 public:
    typedef size_t size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const reference const_reference;

    class iterator {
     public:
        explicit iterator(pointer ptr) : m_ptr(ptr) {}
        iterator operator++() { m_ptr++; return *this; }
        iterator operator++(int unused) {
            iterator i = *this;
            m_ptr++;
            return i;
        }
        reference operator*() { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        bool operator==(const iterator& rhs) { return m_ptr == rhs.m_ptr; }
        bool operator!=(const iterator& rhs) { return m_ptr != rhs.m_ptr; }
     private:
        pointer m_ptr;
    };

    class const_iterator {
     public:
         explicit const_iterator(pointer ptr) : m_ptr(ptr) {}
         const_iterator operator++() { m_ptr++; return *this; }
         const_iterator operator++(int unused) {
             const_iterator i = *this;
             m_ptr++;
             return i;
         }
         const_reference operator*() { return *m_ptr; }
         const pointer operator->() { return m_ptr; }
         bool operator==(const const_iterator& rhs) { return m_ptr == rhs.m_ptr; }
         bool operator!=(const const_iterator& rhs) { return m_ptr != rhs.m_ptr; }
     private:
         const pointer m_ptr;
    };

    /*! Default constructor */
    Vector() : m_size(0), m_capacity(0), m_data(nullptr) {}

    /*!
     * Creates a vector with the desired capacity
     * \param n desired capacity
     */
    explicit Vector(size_type n) : m_size(0), m_capacity(16),
                                m_data(new T[m_capacity])
    {  }

    /*!
     * Creates a vector of desired capacity filled with specified value
     * \param n desired capacity
     * \param elem value to fill with
     */
    Vector(size_type n, T elem) : m_size(n), m_capacity(n),
                               m_data(new T[m_capacity]) {
        fill(m_data, m_data + size(), elem);
    }

    /*!
     * Copy constructor
     * \param t Vector to copy from
     */
    Vector(const Vector &t) : m_size(t.size()), m_capacity(m_size),
                              m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; ++i)
            m_data[i] = t.m_data[i];
    }

    /*!
     * Constructs Vector from std::initializaer list
     * \param l list of initial values for vector
     */
    Vector(std::initializer_list<T> l) : m_size(l.size()), m_capacity(m_size),
                                         m_data(new T[m_size]) {
        copy(l.begin(), l.end(), m_data);
    }

    Vector(Vector&& mover) {
        *this = std::move(mover);
    }

    /*!
     * destructs the vector
     */
    ~Vector() { if (m_data) delete [] m_data; }

    /*!
     * Move assignment
     */
    Vector& operator=(Vector&& mover) {
        if (this != &mover) {
            if (m_data)
                delete [] m_data;

            m_data = mover.m_data;
            m_size = mover.m_size;
            m_capacity = mover.m_capacity;

            mover.m_data = nullptr;
            mover.m_size = 0;
            mover.m_capacity = 0;
        }
        return *this;
    }
    /*!
     * assignment operator
     */
    Vector& operator=(const Vector &other) {
        if (this != &other) {
            m_size = other.size();
            m_capacity = m_size;

            if (m_data)
                delete [] m_data;
            m_data = new T[m_capacity];

            for (int i = 0; i < m_size; ++i)
                m_data[i] = other.m_data[i];
        }
        return *this;
    }

    Vector& operator=(std::initializer_list<T> l) {
        m_size = l.size();
        m_capacity = m_size;

        if (m_data)
            delete [] m_data;
        m_data = new T[m_capacity];

        copy(l.begin(), l.end(), m_data);
        return *this;
    }

    void assign(size_t count, const T& value) {
        if (m_data)
            delete [] m_data;
        m_size = count;
        m_capacity = count;

        m_data = new T[m_capacity];

        fill(m_data, m_data + m_size, value);
    }

    void assign(std::initializer_list<T> l) {
        if (m_data)
            delete [] m_data;
        m_size = l.size();
        m_capacity = m_size;

        m_data = new T[m_capacity];


        copy(l.begin(), l.end() , m_data);
    }

    /*!
     * checks whether the container is empty
     * \retval true container is empty
     * \retval false containter is not empty
     */
    bool empty() const noexcept { return (size() == 0); }

    /*!
     * returns number of elements in vector
     */
    size_type size() const noexcept { return m_size; }

    /*!
     * returns vector current capacity
     */
    size_type capacity() const noexcept { return m_capacity; }

    /*!
     * returns pointer to data member
     */
    pointer data() noexcept { return m_data; }

    /*!
     * returns const pointer to data member
     */
    const pointer data() const noexcept { return m_data; }

    /*!
     * \brief access specified element
     * Doesn't check if index is in range. Doesn't throw.
     * \param index index of specified element
     */
    reference operator[](size_type index) noexcept { return m_data[index]; }

    /*!
     * \brief access specified element
     * \param index index of specified element
     * \throws std::out_of_range if index is not in range
     */
    reference at(size_type index) {
        if (index >= size())
            throw std::out_of_range("Index out of range");
        return m_data[index];
    }

    /*!
     * puts new element at the end of vector.
     * If vector is too small it allocates more memory
     * \param value value to be pushed back
     */
    void push_back(const T &value) {
        if (m_size >= m_capacity) {
            m_capacity *= 2;
            T *data = new T[m_capacity];
            for (int i = 0; i< m_size; i++) {
                data[i] = m_data[i];
            }
            delete [] m_data;
            m_data = data;
        }
        m_data[m_size] = value;
        ++m_size;
    }

    /*!
     * returns iterator to first element
     */
    iterator begin() { return iterator(m_data); }

    const_iterator begin() const { return const_iterator(m_data); }

    /*!
     * returns iterator to element after last
     */
    iterator end() { return iterator(m_data + size()); }

    const_iterator end() const { return const_iterator(m_data); }

    /*!
     * clears the data in container
     * Doesn't change %capacity
     */
    void clear() noexcept { m_size = 0; }


 private:
    size_type m_size;  /*! Number of elements in vector */
    size_type m_capacity;  /*! Capacity of vector */
    pointer m_data;  /*! A pointer to where the data is stored */
};

#endif  // VECTOR_H_
