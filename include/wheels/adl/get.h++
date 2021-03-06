// Wheels - various C++ utilities
//
// Written in 2013 by Martinho Fernandes <martinho.fernandes@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// ADL-enabled get

#ifndef WHEELS_ADL_GET_HPP
#define WHEELS_ADL_GET_HPP

#include <tuple> // get
#include <utility> // declval
#include <cstddef> // size_t

namespace wheels {
    namespace adl {
        namespace detail {
            using std::get;
            template <std::size_t I, typename T,
                      typename Result = decltype(get<I>(std::declval<T>())),
                      bool NoExcept = noexcept(get<I>(std::declval<T>()))>
            Result adl_get(T&& t) noexcept(NoExcept) {
                return get<I>(std::forward<T>(t));
            }
        } // namespace detail

        // Calls get with ADL-lookup include std::get
        template <std::size_t I, typename T,
                  typename Result = decltype(detail::adl_get<I>(std::declval<T>())),
                  bool NoExcept = noexcept(detail::adl_get<I>(std::declval<T>()))>
        Result get(T&& t) noexcept(NoExcept) {
            return detail::adl_get<I>(std::forward<T>(t));
        }
    } // namespace adl
} // namespace wheels

#endif // WHEELS_ADL_SWAP_HPP

