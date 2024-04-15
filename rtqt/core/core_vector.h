/**
 * @file core_vector.h
 * @author TONBUL, Muhammet
*/

#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include <cstddef>
#include <memory>
#include <new>
#include <vector>

namespace rtqt
{
  template <typename _Tp, typename _Allocator>
  struct _Core_vector_base
  {
    typedef ptrdiff_t difference_type;
    typedef size_t    size_type;

  public:
    _Core_vector_base();
    _Core_vector_base(size_type __n);
    virtual ~_Core_vector_base();

  public:
    static _Tp* _M_memory_allocate(size_type __n);
    static void _M_memory_deallocate(_Tp *__ptr, size_type __n);
    static void _M_memory_construct(_Tp *__ptr, size_type __n);
    static void _M_memory_construct(_Tp *__ptr, size_type __n, const _Tp &__x);
    static void _M_memory_destroy(_Tp *__first, _Tp *__last);
    static _Tp* _M_memory_copy(_Tp *__first, _Tp *__last, _Tp *__dst);

  public:
    _Tp *_M_begin;
    _Tp *_M_end;
    _Tp *_M_capacity;
  };

  template <typename _Tp, typename _Allocator>
  inline
  _Core_vector_base<_Tp, _Allocator>
    ::_Core_vector_base()
      : _M_begin(nullptr)
      , _M_end(nullptr)
      , _M_capacity(nullptr)
  {
    // Nothing to do.
  }

  template <typename _Tp, typename _Allocator>
  inline
  _Core_vector_base<_Tp, _Allocator>
    ::_Core_vector_base(size_type __n)
  {
    _M_begin      = _M_memory_allocate(__n);
    _M_end        = _M_begin;
    _M_capacity   = _M_begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  inline
  _Core_vector_base<_Tp, _Allocator>
    ::~_Core_vector_base()
  {
    if (_M_begin) {
      _M_memory_deallocate(_M_begin, (size_type)(_M_capacity - _M_begin));
    }
  }

  template <typename _Tp, typename _Allocator>
  inline 
  _Tp*
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_allocate(size_type __n)
  {
    _Allocator __alloc;
    return __n != 0 ? __alloc.allocate(__n) : nullptr;
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_deallocate(_Tp *__ptr, size_type __n)
  {
    _Allocator __alloc;
    __alloc.deallocate(__ptr, __n);
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_construct(_Tp *__ptr, size_type __n)
  {
    _Allocator __alloc;

    for (; __n > 0; --__n, ++__ptr) {
      __alloc.construct(__ptr, _Tp());
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_construct(_Tp *__ptr, size_type __n, const _Tp &__x)
  {
    _Allocator __alloc;

    for (; __n > 0; --__n, ++__ptr) {
      __alloc.construct(__ptr, __x);
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_destroy(_Tp *__first, _Tp *__last)
  {
    for (; __first != __last; ++__first) {
      __first->~_Tp();
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  _Tp*
  _Core_vector_base<_Tp, _Allocator>
    ::_M_memory_copy(_Tp *__first, _Tp *__last, _Tp *__dst)
  {
    _Allocator __alloc;
    
    for (; __first != __last; ++__first, ++__dst) {
      __alloc.construct(__dst, *__first);
    }

    return __dst;
  }

  template <typename _Tp, typename _Allocator = std::allocator<_Tp>>
  class core_vector
    : public _Core_vector_base<_Tp, _Allocator>
  {
    typedef _Core_vector_base<_Tp, _Allocator> _Base;
    typedef core_vector<_Tp,       _Allocator> _This;

  protected:
    using _Base::_M_memory_allocate;
    using _Base::_M_memory_deallocate;
    using _Base::_M_memory_construct;
    using _Base::_M_memory_destroy;
    using _Base::_M_memory_copy;
    using _Base::_M_begin;
    using _Base::_M_end;
    using _Base::_M_capacity;

  public:
    typedef _Tp                               value_type;
    typedef _Tp*                              pointer;
    typedef const _Tp*                        const_pointer;
    typedef _Tp&                              reference;
    typedef const _Tp&                        const_reference;
    typedef _Tp*                              iterator;
    typedef const _Tp*                        const_iterator;
    typedef typename _Base::size_type         size_type;
    typedef typename _Base::difference_type   difference_type;

  public:
    core_vector();
    core_vector(size_type __n);
    core_vector(size_type __n, const value_type &__x);
    core_vector(const core_vector &__src);
    ~core_vector();

  public:
    reference       operator[](size_type __n);
    const_reference operator[](size_type __n) const;

    reference       at(size_type __n);
    const_reference at(size_type __n) const;

  public:
    reference       front();
    const_reference front() const;

    reference       back();
    const_reference back() const;

  public:
    iterator        begin();
    const_iterator  begin() const;
    const_iterator  cbegin() const;

    iterator        end();
    const_iterator  end() const;
    const_iterator  cend() const;

  public:
    pointer         data();
    const_pointer   data() const;

  public:
    iterator        erase(iterator __pos);
    iterator        erase(const_iterator __pos);
    iterator        erase(iterator __first, iterator __last);
    iterator        erase(const_iterator __first, const_iterator __last);

  public:
    iterator        insert(const_iterator __pos, const value_type &__x);
    iterator        insert(const_iterator __pos, value_type &&__x);

  public:
    template <typename... _Args>
    iterator        emplace(const_iterator __pos, _Args&&... __args);
    template <typename... _Args>
    reference       emplace_back(_Args&&... __args);

  public:
    void            push_back(const value_type &__x);
    void            push_back(value_type &&__x);
    void            pop_back();
    void            clear();

  public:
    void            reserve(size_type __n);
    size_type       capacity() const;
    bool            empty() const;
    size_type       size() const;

  private:
    template <typename... _Args> void _M_insert(const_iterator __pos, _Args&&... __args);
    template <typename... _Args> void _M_insert_end(_Args&&... __args);
    void                              _M_grow(size_type __n);
    size_type                         _M_capacity_grow(size_type __n);
  };

  template <typename _Tp, typename _Allocator>
  inline
  core_vector<_Tp, _Allocator>
    ::core_vector()
      : _Base()
  {
    // Nothing to do.
  }

  template <typename _Tp, typename _Allocator>
  inline
  core_vector<_Tp, _Allocator>
    ::core_vector(size_type __n)
      : _Base(__n)
  {
    _M_memory_construct(_M_begin, __n);
    _M_end            = _M_begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  inline
  core_vector<_Tp, _Allocator>
    ::core_vector(size_type __n, const value_type &__x)
      : _Base(__n)
  {
    _M_memory_construct(_M_begin, __n, __x);
    _M_end            = _M_begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  inline
  core_vector<_Tp, _Allocator>
    ::core_vector(const core_vector &__src)
      : _Base(__src.size())
  {
    pointer __begin = const_cast<pointer>(__src._M_begin);
    pointer __end   = const_cast<pointer>(__src._M_end);
    
    _M_end = _M_memory_copy(__begin, __end, _M_begin);
  }

  template <typename _Tp, typename _Allocator>
  inline
  core_vector<_Tp, _Allocator>
    ::~core_vector()
  {
    _M_memory_destroy(_M_begin, _M_end);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::reference
  core_vector<_Tp, _Allocator>
    ::operator[](size_type __n)
  {
    return *(_M_begin + __n);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_reference
  core_vector<_Tp, _Allocator>
    ::operator[](size_type __n) const
  {
    return *(_M_begin + __n);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::reference
  core_vector<_Tp, _Allocator>
    ::at(size_type __n)
  {
    return *(_M_begin + __n);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_reference
  core_vector<_Tp, _Allocator>
    ::at(size_type __n) const
  {
    return *(_M_begin + __n);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::reference
  core_vector<_Tp, _Allocator>
    ::front()
  {
    return *_M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_reference
  core_vector<_Tp, _Allocator>
    ::front() const
  {
    return *_M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::reference
  core_vector<_Tp, _Allocator>
    ::back()
  {
    return *(_M_end - 1);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_reference
  core_vector<_Tp, _Allocator>
    ::back() const
  {
    return *(_M_end - 1);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::begin()
  {
    return _M_begin;
  }
  
  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_iterator
  core_vector<_Tp, _Allocator>
    ::begin() const
  {
    return _M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_iterator
  core_vector<_Tp, _Allocator>
    ::cbegin() const
  {
    return _M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::end()
  {
    return _M_end;
  }
  
  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_iterator
  core_vector<_Tp, _Allocator>
    ::end() const
  {
    return _M_end;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_iterator
  core_vector<_Tp, _Allocator>
    ::cend() const
  {
    return _M_end;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::pointer
  core_vector<_Tp, _Allocator>
    ::data()
  {
    return _M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::const_pointer
  core_vector<_Tp, _Allocator>
    ::data() const
  {
    return _M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::erase(iterator __pos)
  {
    iterator __dst = __pos;

    if ((__pos + 1) < _M_end) {
      std::move(__dst + 1, _M_end, __dst);
    }

    _M_end--;
    _M_end->~value_type();

    return __dst;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::erase(const_iterator __pos)
  {
    return erase(const_cast<value_type*>(__pos));
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::erase(iterator __first, iterator __last)
  {
    iterator __pos = std::move(__last, _M_end, __first);

    _M_memory_destroy(__pos, _M_end);
    _M_end -= __last - __first;

    return __first;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::erase(const_iterator __first, const_iterator __last)
  {
    return erase(const_cast<value_type*>(__first), const_cast<value_type*>(__last));
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::insert(const_iterator __pos, const value_type &__x)
  {
    const difference_type __n = __pos - _M_begin;

    if (_M_end == _M_capacity || __pos != _M_end) {
      _M_insert(__pos, __x);
    }
    else {
      ::new((void*)_M_end) value_type(__x);
      ++_M_end;
    }

    return _M_begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::insert(const_iterator __pos, value_type &&__x)
  {
    return emplace(__pos, std::move(__x));
  }

  template <typename _Tp, typename _Allocator>
  template <typename... _Args>
  inline
  typename core_vector<_Tp, _Allocator>::iterator
  core_vector<_Tp, _Allocator>
    ::emplace(const_iterator __pos, _Args&&... __args)
  {
    const difference_type __n = __pos - _M_begin;

    if (_M_end == _M_capacity || __pos != _M_end) {
      _M_insert(__pos, std::forward<_Args>(__args)...);
    }
    else {
      ::new((void*)_M_end) value_type(std::forward<_Args>(__args)...);
      ++_M_end;
    }

    return _M_begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  template <typename... _Args>
  inline
  typename core_vector<_Tp, _Allocator>::reference
  core_vector<_Tp, _Allocator>
    ::emplace_back(_Args&&... __args)
  {
    if (_M_end < _M_capacity) {
      ::new((void*)_M_end) value_type(std::forward<_Args>(__args)...);
      ++_M_end;
    }
    else {
      _M_insert_end(std::forward<_Args>(__args)...);
    }

    return back();
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::push_back(const value_type &__x)
  {
    if (_M_end < _M_capacity) {
      ::new((void*)_M_end++) value_type(__x);
    }
    else {
      _M_insert_end(__x);
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::push_back(value_type &&__x)
  {
    if (_M_end < _M_capacity) {
      ::new((void*)_M_end++) value_type(std::move(__x));
    }
    else {
      _M_insert_end(std::move(__x));
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::pop_back()
  {
    --_M_end;
    _M_end->~value_type();
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::clear()
  {
    _M_memory_destroy(_M_begin, _M_end);
    _M_end          = _M_begin;
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::reserve(size_type __n)
  {
    if (__n > size_type(_M_capacity - _M_begin)) {
      _M_grow(__n);
    }
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::size_type
  core_vector<_Tp, _Allocator>
    ::size() const
  {
    return (size_type)(_M_end - _M_begin);
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::size_type
  core_vector<_Tp, _Allocator>
    ::capacity() const
  {
    return (size_type)(_M_capacity - _M_begin);
  }

  template <typename _Tp, typename _Allocator>
  inline
  bool
  core_vector<_Tp, _Allocator>
    ::empty() const
  {
    return _M_begin == _M_end;
  }

  template <typename _Tp, typename _Allocator>
  template <typename... _Args>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::_M_insert(const_iterator __pos, _Args&&... __args)
  {
    iterator __dst = const_cast<value_type*>(__pos);

    if (_M_end != _M_capacity) {
      value_type __x(std::forward<_Args>(__args)...);
      ::new(static_cast<void*>(_M_end)) value_type(std::move(*(_M_end - 1)));
      std::move_backward(__dst, _M_end - 1, _M_end);
      __dst->~value_type();
      ::new(static_cast<void*>(__dst)) value_type(std::move(__x));
      ++_M_end;
    }
    else {
      const size_type __n_pos = size_type(__dst - _M_begin);
      const size_type __n_old = size_type(_M_end - _M_begin);
      const size_type __n_new = _M_capacity_grow(__n_old);
      pointer         __begin = _M_memory_allocate(__n_new);

      ::new((void*)(__begin + __n_pos)) value_type(std::forward<_Args>(__args)...);
      pointer __end = std::uninitialized_move(_M_begin, __dst, __begin);
      __end         = std::uninitialized_move(__dst, _M_end, ++__end); 

      _M_memory_destroy(_M_begin, _M_end);
      _M_memory_deallocate(_M_begin, (size_type)(_M_capacity - _M_begin));

      _M_begin    = __begin;
      _M_end      = __end;
      _M_capacity = __begin + __n_new;
    }
  }

  template <typename _Tp, typename _Allocator>
  template <typename... _Args>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::_M_insert_end(_Args&&... __args)
  {
    const size_type __n_old = size_type(_M_end - _M_begin);
    const size_type __n_new = _M_capacity_grow(__n_old);
    pointer         __begin = _M_memory_allocate(__n_new);
    
    pointer         __end   = std::uninitialized_move(_M_begin, _M_end, __begin);
    ::new((void*)__end) value_type(std::forward<_Args>(__args)...);
    ++__end;

    _M_memory_destroy(_M_begin, _M_end);
    _M_memory_deallocate(_M_begin, (size_type)(_M_capacity - _M_begin));

    _M_begin    = __begin;
    _M_end      = __end;
    _M_capacity = __begin + __n_new;
  }

  template <typename _Tp, typename _Allocator>
  inline
  void
  core_vector<_Tp, _Allocator>
    ::_M_grow(size_type __n)
  {
    pointer __begin = _M_memory_allocate(__n);
    pointer __end   = std::uninitialized_move(_M_begin, _M_end, __begin);

    _M_memory_destroy(_M_begin, _M_end);
    _M_memory_deallocate(_M_begin, (size_type)(_M_capacity - _M_begin));

    _M_begin    = __begin;
    _M_end      = __end;
    _M_capacity = __begin + __n;
  }

  template <typename _Tp, typename _Allocator>
  inline
  typename core_vector<_Tp, _Allocator>::size_type
  core_vector<_Tp, _Allocator>
    ::_M_capacity_grow(size_type __n)
  {
    return (__n > 0) ? (2 * __n) : 1;
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator==(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return ((__lhs.size() == __rhs.size()) && std::equal(__lhs.begin(), __lhs.end(), __rhs.begin()));
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator!=(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return ((__lhs.size() != __rhs.size()) || !std::equal(__lhs.begin(), __lhs.end(), __rhs.begin()));
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator<(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return std::lexicographical_compare(__lhs.begin(), __lhs.end(), __rhs.begin(), __rhs.end());
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator>(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return __rhs < __lhs;
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator<=(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return !(__rhs < __lhs);
  }

  template <typename _Tp, typename _Allocator>
  inline bool
  operator>=(const core_vector<_Tp, _Allocator> &__lhs, const core_vector<_Tp, _Allocator> &__rhs)
  {
    return !(__lhs < __rhs);
  }
} // namespace rtqt

#endif /* !CORE_VECTOR_H */