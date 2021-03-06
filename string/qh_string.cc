#include "qh_string.h"

#include <string.h>
#include <cstring>
#include <stdio.h>

namespace qh
{
    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        len_ = strlen(s);
        if(len_ == 0)
        {
            data_ = NULL;
            len_ = 0;
            return;
        }

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
        if(len == 0)
        {
            data_ = NULL;
            len_ = 0;
            return;
        }

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
            data_ = NULL;
            len_ = 0;
            return;
        }

        len_ = rhs.len_;
        data_ = new char[len_ + 1];
        if( data_ )
        {
            memcpy(data_, rhs.data_, len_ + 1);
        }
        else
            len_ = 0;
    }

    string& string::operator=( const string& rhs )
    {
        if(&rhs != this)
        {
            if(data_ != NULL)
                delete []data_;

            if(rhs.data_ == NULL)
            {
                data_ = NULL;
                len_ = 0;
            }
            else
            {
                len_ = rhs.len_;
                data_ = new char[len_ + 1];
                if( data_ )
                {
                    memcpy(data_, rhs.data_, len_ + 1);
                }
                else
                    len_ = 0;
            }
        }
        return *this;
    }

    string::~string()
    {
        if(data_ != NULL)
            delete []data_;
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
