#pragma once
#include <iostream>
#include <concepts>
#include <numeric>

template<typename I> 
requires std::integral<I>   //"per ogni I intero"
class rational
{
private:
	I num_;
	I den_;
	void semplificazione()
	{
		if (num_!=0 && den_!=0)
		{
			I mcd= std::gcd(num_,den_);
			num_ /= mcd;
			den_ /= mcd;
		}
	}
	
public:
	rational() :num_(I{0}), den_(I{1}) {}   //num_(0), den_(1)

	rational(const I& pn, const I&	pd) : num_(pn), den_(pd)
	{
		if (den_==0)
		{
			if (num_!=0)
			{
				num_=1;
			}
			else
			{
				num_=0;
			}
		}
		else
		{
			semplificazione();
		}
	}
	
	I num() const { return num_; }
	I den() const { return den_; }
	
	rational& operator+=(const rational& other)
	{
		if ((den_==0 && num_!=0) || (other.den_==0 && other.num_!=0))
		{
			num_=1;
			den_=0;
		}
		else if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0))
		{
			num_=0;
			den_=0;
		}
		else 
		{
			num_ = num_*other.den_ + other.num_*den_;
			den_ = den_*other.den_; 
			semplificazione();
		} 
		return *this;
	}
	rational operator+(const rational& other) const 
	{
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	rational& operator-=(const rational& other)
	{
		if ((den_==0 && num_!=0) || (other.den_==0 && other.num_!=0))
		{
			num_=1;
			den_=0;
		}
		else if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0))
		{
			num_=0;
			den_=0;
		}
		else 
		{
			num_ = num_*other.den_ - other.num_*den_;
			den_ = den_*other.den_;
			semplificazione();
		} 
		return *this;
	}
	rational operator-(const rational& other) const 
	{
		rational ret = *this;
		ret -= other;
		return ret;
	}
	
	rational& operator*=(const rational& other)
	{
		if ((den_==0 && num_!=0) || (other.den_==0 && other.num_!=0))
		{
			num_=1;
			den_=0;
		}
		else if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0))
		{
			num_=0;
			den_=0;
		}
		else 
		{
			num_ *= other.num_ ;
			den_ *= other.den_; 
			semplificazione();
		} 
		return *this;
	}
	rational operator*(const rational& other) const 
	{
		rational ret = *this;
		ret *= other;
		return ret;
	}
	
	rational& operator/=(const rational& other)
	{
		if ((den_==0 && num_!=0) || (other.den_==0 && other.num_!=0))
		{
			num_=1;
			den_=0;
		}
		else if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0))
		{
			num_=0;
			den_=0;
		}
		else 
		{
			num_ *= other.den_;
			den_ *= other.num_; 
			semplificazione();
		} 
		return *this;
	}
	rational operator/(const rational& other) const 
	{
		rational ret = *this;
		ret /= other;
		return ret;
	}
	
	//semplificazione
};

template<typename I>   
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.den()==0)
	{
		if (r.num()==0)
		{
			os << "NaN";
		}
		else
		{
			os << "Inf";
		}
	}
	else
	{
		os << r.num() <<"/" << r.den();
	}
	return os;
}

		