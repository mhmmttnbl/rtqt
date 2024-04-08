/**
 * @file core_functional.h
 * @author TONBUL, Muhammet
*/

#ifndef CORE_FUNCTIONAL_H
#define CORE_FUNCTIONAL_H

namespace rtqt
{
  template <typename _Tp, typename _Result>
  struct core_unary_function
  {
    typedef _Tp       argument_type;
    typedef _Result   result_type;
  };

  template <typename _Tp1, typename _Tp2, typename _Result>
  struct core_binary_function
  {
    typedef _Tp1      first_argument_type;
    typedef _Tp2      second_argument_type;
    typedef _Result   result_type;
  };

  template <typename _Tp>
  struct core_less
    : public core_binary_function<_Tp, _Tp, bool>
  {
    constexpr bool
    operator()(const _Tp &__x, const _Tp &__y)
    {
      return __x < __y;
    }
  };

  template <typename _Tp>
  struct core_less<_Tp*>
    : public core_binary_function<_Tp*, _Tp*, bool>
  {
    constexpr bool
    operator()(const _Tp *__x, const _Tp *__y)
    {
      return __x < __y;
    }
  };

  template <typename _Tp>
  struct core_greater
    : public core_binary_function<_Tp, _Tp, bool>
  {
    constexpr bool
    operator()(const _Tp &__x, const _Tp &__y)
    {
      return __x > __y;
    }
  };

  template <typename _Tp>
  struct core_greater<_Tp*>
    : public core_binary_function<_Tp*, _Tp*, bool>
  {
    constexpr bool
    operator()(const _Tp *__x, const _Tp *__y)
    {
      return __x > __y;
    }
  };

  template <typename _Tp>
  struct core_identity
    : public core_unary_function<_Tp, _Tp>
  {
    _Tp& 
    operator()(_Tp &__x) const
    {
      return __x;
    }

    const _Tp& 
    operator()(const _Tp &__x) const
    {
      return __x;
    }
  };

  template <typename _Pair>
  struct core_select1st
    : public core_unary_function<_Pair, typename _Pair::first_type>
  {
    typename _Pair::first_type& 
    operator()(_Pair &__x) const
    {
      return __x.first;
    }

    const typename _Pair::first_type& 
    operator()(const _Pair &__x) const
    {
      return __x.first;
    }
  };

  template <typename _Pair>
  struct core_select2nd
    : public core_unary_function<_Pair, typename _Pair::second_type>
  {
    typename _Pair::second_type& 
    operator()(_Pair &__x) const
    {
      return __x.second;
    }

    const typename _Pair::second_type& 
    operator()(const _Pair &__x) const
    {
      return __x.second;
    }
  };
} // namespace rtqt

#endif /* !CORE_FUNCTIONAL_H */