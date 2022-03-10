#ifndef CPLONG_H_
#define CPLONG_H_
#include <iostream>
using namespace std;
#ifndef diph_ulong_meks
#define	diph_ulong_meks	((unsigned long)(~0L))		/* 0xFFFFFFFF */
#endif

#ifndef diph_long_meks
#define	diph_long_meks	((long)(diph_ulong_meks >> 1))	/* 0x7FFFFFFF */
#endif

#ifndef diph_long_min
#define	diph_long_min	((long)(~diph_long_meks) + 1)		/* 0x80000000 */
#endif

// meks long 9223372036854775807 // 0h13 dizits
#ifndef _nmbr_dec_dizits_long_meks_
#define	_nmbr_dec_dizits_long_meks_	0x13		/* 0x80000000 */
#endif

// meks long "0h7???????????????" // 0h10 dizits
#ifndef _nmbr_heks_dizits_long_meks_
#define	_nmbr_heks_dizits_long_meks_	0x10		/* 0x80000000 */
#endif

class cplong {
private:
	long value; int pl;
	inline void handle_overphlo();
	inline void handle_underphlo();
public:
	static int minimum_pl; static const int pl_dec_phur_divizn;//pl_dec_phur_divizn
	static const long min_long ;
	static const long meks_long ;
	static const long nmbr_dec_dizits_long_meks ;
	static const long nmbr_heks_dizits_long_meks ;

	static int bitsize(long value);

	cplong(const long=0,const int=0);
	cplong(const string& str_plong);
	string to_string();
	int inc_pl(int to_pl); int dec_pl(int to_pl); inline int trim_ziroz();
	long get_value();
	long get_pl();

	cplong operator++ ();
	cplong operator++( int );
	cplong operator-- ();
	cplong operator--( int );

	bool operator <(const cplong& other);
	bool operator >(const cplong& other);
	bool operator <=(const cplong& other);
	bool operator >=(const cplong& other);
	bool operator ==(const cplong& other);
	bool operator !=(const cplong& other);

	cplong operator- ();

	cplong operator+(const cplong& other);
	cplong& operator+=(const cplong& other);
	friend cplong operator+(long a, const cplong& b);

	cplong operator-(const cplong& other);
	cplong& operator-=(const cplong& other);
	friend cplong operator-(long a, const cplong& b);

	cplong operator*(const cplong& other);
	cplong& operator*=(const cplong& other);
	friend cplong operator*(long a, const cplong& b);

	cplong operator%(const cplong& other);
	cplong& operator%=(const cplong& other);
	friend cplong operator%(long a, const cplong& b);

	cplong div_pl(const cplong& b, int droppl);
	cplong operator/(const cplong& b);
	cplong& operator/=(const cplong& b);
	friend cplong operator/(long a, const cplong& b);

	friend std::ostream& operator<<(std::ostream& os, const cplong& aplong);
	virtual ~cplong();
};
#endif /* CPLONG_H_ */
