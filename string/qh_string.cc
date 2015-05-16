#include "qh_string.h"

#include <string.h>
#include <cstring>
#include <stdio.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        len_ = strlen(s);
        data_ = new char[len_ + 1];
        if( data_ )
        {
            memcpy(data_, s, len_);
            data_[len_] = '\0';
        }
        else
            len_ = 0;
    }

    string::string( const char* s, size_t len )
    {
        size_t sourceLen = strlen(s);
        len_ = len > sourceLen ? sourceLen : len;

        data_ = new char[len_ + 1];
        if( data_ )
        {
            memcpy(data_, s, len_);
            data_[len_] = '\0';
        }
        else
            len_ = 0;
    }

    string::string( const string& rhs )
    {
        if(rhs.data_ == NULL)
        {
            string();
            return;
        }
        len_ = rhs.len_;
        data_ = new char[len_ + 1];
        if( data_ )
        {
            memcpy(data_, rhs.data_, len_);
            data_[len_] = '\0';
        }
        else
            len_ = 0;
    }

    string& string::operator=( const string& rhs )
    {
        if(&rhs != this)
        {
            string(rhs);
        }
        return *this;
    }

    string::~string()
    {
        delete []data_;
        len_ = 0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char* string::operator[]( size_t index )
    {
        if(index <= len_)
        {
            return data_ + index;
        }
        return NULL;
    }
}
