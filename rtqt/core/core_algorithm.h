/**
 * @file core_algorithm.h
 * @author TONBUL, Muhammet
*/

#ifndef CORE_ALGORITHM_H
#define CORE_ALGORITHM_H

namespace rtqt
{
  template <typename _ForwardIterator>
  inline _ForwardIterator
  core_minimum_element(_ForwardIterator __first, _ForwardIterator __last)
  {
    if (__first == __last) {
      return __last;
    }

    _ForwardIterator __tmp = __first;

    while (++__first != __last) {
      if (*__first < *__tmp) {
        __tmp = __first;
      }
    }

    return __tmp;
  }
} // namespace rtqt

#endif /* !CORE_ALGORITHM_H */