/**
 * @file core_pair.h
 * @author TONBUL, Muhammet
*/

#ifndef CORE_PAIR_H
#define CORE_PAIR_H

#include <type_traits>

namespace rtqt
{
  template <typename _Tp1, typename _Tp2>
  class core_pair
  {
  public:
    typedef _Tp1 first_type;
    typedef _Tp2 second_type;

  public:
    template <typename _Tpp1 = _Tp1,
              typename _Tpp2 = _Tp2,
              typename = std::enable_if_t<std::is_default_constructible<_Tpp1>::value &&
                                          std::is_default_constructible<_Tpp2>::value>>
    constexpr core_pair()
      : first()
      , second()
    {
      // Nothing to do.
    }
    
    template <typename _Tpp1 = _Tp1,
              typename _Tpp2 = _Tp2,
              typename = std::enable_if_t<std::is_copy_constructible<_Tpp1>::value &&
                                          std::is_copy_constructible<_Tpp2>::value>>
    constexpr core_pair(const _Tp1 &__first, const _Tp2 &__second)
      : first(__first)
      , second(__second)
    {
      // Nothing to do.
    }

    template <typename _Tpp1, 
              typename _Tpp2,
              typename = std::enable_if_t<std::is_convertible<_Tpp1, _Tp1>::value &&
                                          std::is_convertible<_Tpp2, _Tp2>::value>>
    constexpr core_pair(const core_pair<_Tpp1, _Tpp2> &__src)
      : first(__src.first)
      , second(__src.second)
    {
      // Nothing to do.
    }

    core_pair(const core_pair &__src) = default;
    core_pair(core_pair &&__src) = default;

  public:
    _Tp1 first;
    _Tp2 second;
  };

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator==(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return ((__lhs.first == __rhs.first) && (__lhs.second == __rhs.second));
  }

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator!=(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return !(__lhs == __rhs);
  }

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator<(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return __lhs.first < __rhs.first || (!(__lhs.first < __rhs.first) && __rhs.second < __lhs.second);
  }

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator>(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return __rhs < __lhs;
  }

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator<=(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return !(__rhs < __lhs);
  }

  template <typename _Tp1, typename _Tp2>
  constexpr inline
  bool
  operator>=(const core_pair<_Tp1, _Tp2> &__lhs, const core_pair<_Tp1, _Tp2> &__rhs)
  {
    return !(__lhs < __rhs);
  }
} // namespace rtqt

#endif /* !CORE_PAIR_H */