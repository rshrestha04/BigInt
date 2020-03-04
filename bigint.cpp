/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "bigint.h"
#include <cmath>
#include <sstream>
#include <ostream>

namespace csis3700{
    
    
    
    bigint::bigint(long long l){
        capacity=20;
        used=0;
        digits= new uint8_t[capacity];
        if(l==0){
            *digits=0; 
            negative = false;
            used++;
        }
        
        else if (l>0){
            int rem; 
            negative = false;
            int x=0;
            while (l>0){
                
           
                rem=l%10;
                l=l/10;
                digits[x]=rem;
                 x++;
                 used++;
            }
            
        }
        else if (l<0){
            l=l*(-1);
            negative = true;
             
            int rem; 
            int x=0;
            while (l>0){
           
                rem=l%10;
                l=l/10;
                digits[x]=rem;
                 x++;
                 used++;
            }
            
        }
    }
    
     bigint::bigint(uint8_t d[], std::size_t ndigits, bool is_negative){
         capacity =20;
         used=0;
         negative= is_negative;
         digits= new uint8_t [capacity];
         for (int x=0;x < ndigits;x++){
             digits[x]=d[x];
             used++;
         }
         
         
         
         
     }
     
     bigint::bigint (const bigint& other){
         digits= new uint8_t[other.capacity];
         capacity = other.capacity;
         used = other.used;negative= other.negative;
         for(size_t i=0; i<other.used; i++) digits[i] = other.digits[i];
         
     }
     
     bigint::~bigint(){
         delete []digits;
     }
     
     bigint bigint:: negate() const{
         bigint a;
         if (*this==a) return a ;
         bool Is_negative;
         if(negative ){
             Is_negative=false; 
             }
         else Is_negative =true;
        bigint neg(digits,used,Is_negative );
        return neg;
     
    }
    
     
     std::size_t bigint:: get_digit_count() const{
         return used;
     }
     uint8_t bigint:: get_digit(size_t i) const{
         return  digits[i];
     }
     bool bigint:: is_negative() const{
         return negative;
     }
     
     
     bigint bigint:: abs() const{
         bigint abs(digits,used,false);
         
         return abs;
         
     }
     
      void bigint::operator =(const bigint& other){
          uint8_t *new_digits;
          if(this==&other)
             return;
          if (capacity!=other.capacity){
              new_digits = new uint8_t[other.capacity];
              delete[] digits;
              digits = new_digits;
              capacity = other.capacity;
          }
          used =other.used;
          negative= other.negative;
          for(size_t i= 0; i<other.used; i++) digits[i]= other.digits[i];
          
      }
     
    bool operator<(const bigint &i1,const bigint &i2) {
        
        if (i2.is_negative()==true && i1.is_negative()==false){
            return false;
        } 
        if (i2.is_negative()==false && i1.is_negative()==true){
            return true;
        } 
        
        if (i1.is_negative()==false && i2.is_negative()==false){
            
            if (i1.get_digit_count()<i2.get_digit_count()){
            return true;
            }
        
            else if (i1.get_digit_count()>i2.get_digit_count()){
            return false;
            }
        
            else if (i1.get_digit_count()==i2.get_digit_count()){
                for (int x=i1.get_digit_count()-1; x>=0;x--){
                    if ( i1.get_digit(x) != i2.get_digit(x)){
                    return( i1.get_digit(x) < i2.get_digit(x));  
                    }
                }
            return false;
            }
        }
        if (i1.is_negative()==true && i2.is_negative()==true){
            if (i1.get_digit_count()>i2.get_digit_count()){
            return true;
            }
        
            else if (i1.get_digit_count()<i2.get_digit_count()){
            return false;
            }
        
            else if (i1.get_digit_count()==i2.get_digit_count()){
                for (int x=i1.get_digit_count()-1; x>=0;x--){
                    if ( i1.get_digit(x) != i2.get_digit(x)){
                    return( i1.get_digit(x) > i2.get_digit(x));  
                    }
                }
            return false;
            }
            
        }
    }
      
    bool operator==(const bigint& i1,const bigint& i2){
        if (i1.is_negative()!=i2.is_negative()){
            return false;
        }
        if(i1.get_digit_count()!=i2.get_digit_count()){
            return false;
        }
        else if (i1.get_digit_count()==i2.get_digit_count()){
            for (int x=0; x<i1.get_digit_count();x++){
                if ( i1.get_digit(x) != i2.get_digit(x)){
                    return false;  
                }
            }
            return true;  
        }
     
    }
    
    void bigint:: operator +=(const bigint& other){
        /*
        if (used < other.get_digit_count()){
            
            for (int x=used; x<other.get_digit_count();x++){
            digits[x]=0;
            used++;
            }    
        }
        int num, rem;
        
        for (int x=0;x<used;x++){
            if(x>=other.get_digit_count()){
                if ((digits[x]>9)&& x == used-1){
                num=digits[x];
                rem= num%10;
                num=num/10;
                digits[x]=rem;
                digits[x+1]=0;
                digits[x+1]+=num;
                used++;
                
                }
                else if (digits[x]>9){
                num=digits[x];
                rem= num%10;
                num=num/10;
                digits[x]=rem;
                digits[x+1]+=num;
                
                }
                else  digits[x]+=0;
                   
                
            }
           
            else if (((digits[x]+other.get_digit(x))>9)&& x == used-1){
                num=digits[x]+other.get_digit(x);
                rem= num%10;
                num=num/10;
                digits[x]=rem;
                digits[x+1]=0;
                digits[x+1]+=num;
                used++;
                
            }
            else if ((digits[x]+other.get_digit(x))>9){
                num=digits[x]+other.get_digit(x);
                rem= num%10;
                num=num/10;
                digits[x]=rem;
                digits[x+1]+=num;
                
            }
            else { digits[x]+=other.get_digit(x);
            }   
        }*/
        
        if (negative != other.is_negative()){
            bool neg =negative;
            negative = false;
            *this-=other.abs();
            negative=neg;
            negative = this->abs()<other.abs() ? other.is_negative(): negative;
           return;
        }
        
        
        int size = std::max( used,other.get_digit_count() )+1;
        
        uint8_t *copy= new uint8_t[size];
        for (int x=0; x<size; x++){
            copy[x]=0;        
        }
        
        int num1,num2,carry ;
        carry=0;
        
        for (int x=0; x<size; x++){
            if (x<used){
                num1= digits[x];
            }
            else num1=0;
            
            if (x<other.get_digit_count()){
                num2= other.get_digit(x);
            }
            else num2=0;
            
            copy[x]=(num1+num2+carry)%10;
            carry=(num1+num2+carry)/10;
            
        }
        used= copy[size-1]==0 ? size-1:size;
        
        
        
        delete []digits;
        digits=copy;
        
        
    }
    
    
    void bigint::operator*=(const bigint& other){ 
        
        if((used==1 && digits[0]==0) ||(other.get_digit_count()==1 && other.get_digit(0)==0) ){
            digits[0]=0;
            used=1;
            negative= false;
            return;
        } 
      
        negative= (negative==other.is_negative())? false : true;
        
        int size= used+other.get_digit_count();
        
        uint8_t *multi= new uint8_t[size];
        
        for (int x=0;x<size;x++){
            multi[x]=0;
        }
        
        
        
        for(int x=0;x<used;x++){
            int carry=0;
            for(int y=0;y<other.get_digit_count();y++){
               
                multi[x+y]+=(digits[x]* other.get_digit(y))%10;
                 carry=(digits[x]*other.get_digit(y))/10;
                multi[x+1+y]+=carry; 
                
            }
            
            
        
        }
        
        int num,carry2;
        for (int x=0; x<size;x++){
            num = multi[x]%10;
            carry2 = multi[x]/10; 
            multi[x]=num;
            multi[x+1]+=carry2;
        }
        
        used= multi[size-1]==0? size-1:size;
        delete [] digits;
        digits=multi;
        
    }
    void bigint::operator-=(const bigint& other){
        
        if(negative !=other.is_negative()){
            if (negative){
                bool neg= negative;
                negative = false;
                *this+= other.abs();
                negative = true;
                return;
            }
            if (other.is_negative()){
                negative = false;
                *this+= other.abs();
                negative = false;
                return;
            }
         }
      
        negative = *this<other ? other.is_negative(): negative;
        int size = used >= other.get_digit_count()? used: other.get_digit_count();
        
        uint8_t *subtract=new uint8_t[size];
        for (int x=0;x<size;x++) {
            subtract[x]=0;
        }
        
        uint8_t copy1[used];
        
        
        
        
        for(int x=0;x<used;x++){ 
        copy1[x]=digits[x];
        }
        bigint copyself(copy1,used,false);
        bigint copy_other= other.abs();
        
        
        int borrow= 0;
        uint8_t num1;
        uint8_t num2;
        
        for(int x=0;x<size;x++){
            num1=used >x? digits[x]:0;
            num2 = other.get_digit_count()>x? other.get_digit(x):0;
            subtract[x] = copy_other < copyself? num1-num2-borrow: num2-num1-borrow;
            if (subtract[x]>10){
                subtract[x] = copy_other < copyself? num1-num2-borrow+10: num2-num1-borrow+10;
                borrow=1;
                
            }
            else (borrow=0);
            
        }
        
        while(subtract[size-1]==0) size--;
        used=size;
         
       delete [] digits;
       digits=subtract;
       subtract=nullptr;
       
    }
    
    bigint operator+( const bigint &i1,const bigint &i2){
        bigint answer;
        answer+= i1;
        answer+= i2;
        return answer;
    }
    
    bigint operator -(const bigint &i1,const bigint &i2){
        bigint subs;
        subs-= i1;
        subs-= i2;
        return subs;
    }
    
     bigint operator *(const bigint &i1,const bigint &i2){
        if((i1.get_digit_count()==1 && i1.get_digit(0)==0) ||(i2.get_digit_count()==1 && i2.get_digit(0)==0) ){
            bigint a;
            
            return  a; 
        } 
        bigint mult(1);
        mult*= i1;
        mult*= i2;
        return mult;
    }
     
    std::ostream& operator <<(std::ostream& out, const bigint &i){
        if(i.is_negative()){
            out << "-";
        }
        
        //out <<"0";
        for (std::size_t x=i.get_digit_count();x>0;x--){
            
            int b= i.get_digit(x-1);
            out<< b;
        }
        return out;
    }
    /*
    void bigint::operator /=(const bigint& other){
        
        uint8_t *quotient = new uint8_t[used];
        uint8_t divpart= new uint8_t[used];
        
        for (int x=0;x<used;x++){
            quotient[x]=0;
            divpart[x]=0;
        } 
        
        int num = other.used;
        for (int x=0; x < num; x++ ){
        divpart[x]=digits[x];
        }
        
        bigint part(divpart,num,false);
        
        while(part < *this){
            divpart[num]=digits[num];
            num++;
            bigint copypart(divpart,num,false);
            part= copypart;
        }
        
        int answer=1;
        bigint sub,rem;
        while(rem < other.abs() || rem==other){
            
            bigint sub,rem;
            sub =other*answer;
            rem= part-sub;
            answer++;
        }
        
        quotient[num]=answer;
     * }
     * 
     * */
        
        
        
        
        
        
        
    
    
    
        
        
}
    

     
     
    
     
    


