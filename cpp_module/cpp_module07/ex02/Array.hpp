#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename Type>
class Array
{
    private:
        unsigned int    _arraySize;
        Type*           _array;

    public:
        /* OCCF */
        Array()
            : _arraySize(0), _array(NULL)
        {}
        Array(unsigned int n)
            : _arraySize(n), _array(new Type[_arraySize])
        {}
        Array(const Array& origin)
            : _arraySize(origin._arraySize), _array(new Type[_arraySize])
        {
            for (unsigned int i = 0; i < this->_arraySize; i++)
                this->_array[i] = origin._array[i];
        }
        Array& operator=(const Array& origin)
        {
            if (this != &origin)
            {
                delete[] _array;
                this->_arraySize = origin._arraySize;
                this->_array = new Type[this->_arraySize];
                for (unsigned int i = 0; i < this->_arraySize; i++)
                    this->_array[i] = origin._array[i];
            }
            return *this;
        }
        ~Array()
        {
            if (this->_array != NULL)
                delete[] _array;
        }

        /* member functions */
        Type&           operator[](unsigned int index) const
        {
            if (index < 0 || index >= this->_arraySize)
                throw std::exception();
            return this->_array[index];
        }
        // const Type&     operator[](unsigned int index) const
        // {
        //     if (index < 0 || index >= this->_arraySize)
        //         throw std::exception();
        //     return this->_array[index];
        // }
        unsigned int    size() const
        {
            return this->_arraySize;
        }
};

# include "./Array.tpp"

#endif
