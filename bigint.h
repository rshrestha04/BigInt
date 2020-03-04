/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bigint.h
 * Author: Ronish Shrestha
 *
 * Created on February 20, 2018, 7:46 PM
 */

#ifndef BIGINT_H
#define BIGINT_H

namespace csis3700{
    class bigint{
        public:
            typedef unsigned char uint8_t;  
            bigint(long long l=0);
            bigint(uint8_t d[], std::size_t ndigits, bool is_negative);
            bigint(const bigint& other);
            ~bigint();
            
            bigint negate() const;
            std::size_t get_digit_count() const;
            uint8_t get_digit(size_t i) const;
            bool is_negative() const;
            bigint abs() const;
            
            /*-------------------operators-----------------------*/
            void operator +=(const bigint& other);
            void operator*=(const bigint& other);
            void operator-=(const bigint& other);
            void operator =(const bigint& other);
            void operator /=(const bigint& other);
             
            
            
            
            
            
           
            
        private:
            uint8_t* digits;
            std::size_t capacity;
            std::size_t used;
            bool negative;
            
            
    };
    
   /*--------------- operator overloading---------------------*/
    
   bool operator<(const bigint &i1,const bigint &i2);
   bool operator==(const bigint& i1,const bigint& i2);
   bigint operator+( const bigint &i1,const bigint &i2);
   bigint operator *(const bigint &i1,const bigint &i2);
   bigint operator -(const bigint &i1,const bigint &i2);
   std::ostream &operator <<(std::ostream& out, const bigint &i);
   
}



#endif /* BIGINT_H */

