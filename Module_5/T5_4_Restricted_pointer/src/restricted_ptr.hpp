#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/
template <typename T> class RestrictedPtr
{
    public:
        RestrictedPtr() : ptr_(nullptr), ref_counter_(new int(1)){}
        RestrictedPtr(T *ptr): ptr_(ptr), ref_counter_(new int(1)){}
        RestrictedPtr(const RestrictedPtr<T> &a)
        {
            if (a.GetRefCount() == 3)
            {
                ptr_ = nullptr;
                ref_counter_ = new int(1);
                return;
            }
            ptr_ = a.ptr_;
            ref_counter_ = a.ref_counter_;
            (*ref_counter_)++;
            return;
        }
        ~RestrictedPtr()
        {
            (*ref_counter_)--;
            if (*ref_counter_ == 0)
            {
                delete ptr_;
                delete ref_counter_;
            }
        }
        RestrictedPtr<T>& operator=(const RestrictedPtr &a)
        {
            if (a.GetRefCount() == 3)
            {
                ptr_ = nullptr;
                ref_counter_ = new int(1);
                return *this;
            }
            delete ptr_;
            delete ref_counter_;
            ptr_ = a.ptr_;
            ref_counter_ = a.ref_counter_;
            (*ref_counter_)++;
            return *this;
        }
        T &GetData()
        {
            return *ptr_;
        }
        T *GetPointer() const
        {
            return ptr_;
        }
        int GetRefCount() const
        {
            return *ref_counter_;
        }
    private:
        T *ptr_;
        int *ref_counter_;
};
#endif