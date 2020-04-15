#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

#include <cstddef>

namespace ft
{
	template <typename T1, typename T2>
	class pair
	{
		public:
		T1 first;
		T2 second;

		pair(): first(T1()), second(T2()) {}
		~pair() {}
		pair(const T1& x, const T2& y): first(x), second(y) {}
		pair(const pair<T1, T2>& c):
			first(c.first), second(c.second){}
		pair<T1, T2>& operator=(const pair<T1, T2>& c) {
			first = c.first;
			second = c.second;
			return *this;
		}
	};

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;;
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first || 
				((lhs.first == rhs.first) && lhs.second < rhs.second));
	}

	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs > rhs);
	}

	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return rhs < lhs;
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}
}

#endif