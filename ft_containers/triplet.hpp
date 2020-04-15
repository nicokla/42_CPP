#ifndef FT_TRIPLET_HPP
#define FT_TRIPLET_HPP

#include <cstddef>

namespace ft
{
	template <typename T1, typename T2, typename T3>
	class triplet
	{
		public:
		T1 first;
		T2 second;
		T3 third;

		triplet(): first(T1()), second(T2()), third(T3()) {}
		~triplet() {}
		triplet(const T1& x, const T2& y, const T3& z): 
			first(x), second(y), third(z){}
		triplet(const triplet<T1, T2, T3>& c):
			first(c.first), second(c.second), third(c.third){}
		triplet<T1, T2, T3>& operator=(const triplet<T1, T2, T3>& c) {
			first = c.first;
			second = c.second;
			third = c.third;
			return *this;
		}
	};

}

#endif