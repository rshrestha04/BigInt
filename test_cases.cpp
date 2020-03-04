/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "catch.hpp"
#include "bigint.h"
#include <sstream>
#include <ostream> 

using namespace std;
using namespace csis3700;
 

TEST_CASE (" constructor should not cause error", "[bigint]"){
  bigint a;
  bigint b(2990);
  bigint c(-123);
}

TEST_CASE("array constructor should not cause error","[bigint]"){
    uint8_t d[]={1,2,3,4,5};
    bigint a(d,5,false);
}

TEST_CASE("checking constructor when just declared","[bigint]"){
    bigint a;
    REQUIRE(a.get_digit_count()==1);
    REQUIRE(a.get_digit(0)==0);
}

TEST_CASE("Checking second constructor","[bigint]"){
    bigint a(100);
    REQUIRE(a.get_digit_count()==3);
    REQUIRE(a.get_digit(0)==0);
    REQUIRE(a.get_digit(1)==0);
    REQUIRE(a.get_digit(2)==1);
    bigint b(23489);
    REQUIRE(b.get_digit(0)==9);
    REQUIRE(b.get_digit(1)==8);
    REQUIRE(b.get_digit(2)==4);
    REQUIRE(b.get_digit(3)==3);
    REQUIRE(b.get_digit(4)==2);
    REQUIRE(b.get_digit_count()==5);
    bigint c(-1234);
    REQUIRE(c.is_negative()==true);
    REQUIRE(c.get_digit(0)==4);
    REQUIRE(c.get_digit_count()==4);
    REQUIRE(c.get_digit(1)==3);
    REQUIRE(c.get_digit(2)==2);
    REQUIRE(c.get_digit(3)==1);
}

TEST_CASE("checking third constructor","[bigint]"){
    uint8_t a[]={2,3,4,5,6,7,8,9};
    bigint b(a,8,false);
    a[2]=45;
    REQUIRE(b.get_digit_count()==8);
    REQUIRE(b.get_digit(0)==2);
    REQUIRE(b.get_digit(1)==3);
    REQUIRE(b.get_digit(2)==4);
    REQUIRE(b.get_digit(3)==5);
    REQUIRE(b.get_digit(4)==6);
    REQUIRE(b.get_digit(5)==7);
    REQUIRE(b.get_digit(6)==8);
    REQUIRE(b.get_digit(7)==9);
    REQUIRE(b.is_negative()==false);
   
}

TEST_CASE("checking negate","[bigint]"){
    bigint a(-91234);
    bigint b(123);
    bigint c = a.negate();
    bigint d =b.negate();
    REQUIRE(c.is_negative()==false);
    REQUIRE(d.is_negative()==true);
    REQUIRE(c.get_digit_count()==5);
    REQUIRE(c.get_digit(0)==4);
    REQUIRE(d.get_digit_count()==3);
    REQUIRE(d.get_digit(0)==3);
    bigint f;
    f.negate();
    REQUIRE(f.is_negative()==false);
    
    
}


TEST_CASE("checking abs","[bigint]"){
    uint8_t a[]={9,9,9,9,9,9,9,9,9,9,9};
    uint8_t b[]={4,5,6,7,8,9,1,3,4,5};
   
    bigint c(a,11,true);
    bigint d (b,10,false);
    
    bigint e = c.abs();
    REQUIRE(e.is_negative() == false);
    REQUIRE(e.get_digit(3)==9);
    
    
}

TEST_CASE("checking < operator","[bigint]"){
    bigint a(1234);
    bigint b(456);
    bigint c(2143);
    bigint d(12345);
    bigint e(12344);
    REQUIRE((a<b)==false);
    REQUIRE((a<c)==true);
    REQUIRE((c<a)==false);
    REQUIRE((e<d)==true);
    REQUIRE((d<e)==false);
}

TEST_CASE("checking == operator","[bigint]"){
bigint a(145566);
bigint b (123);
bigint c(245566);
bigint d(145567);
bigint e(145566);
REQUIRE((a==b)==false);
REQUIRE((a==c)==false);
REQUIRE((a==d)==false);
REQUIRE((a==e)==true);

}

TEST_CASE("checking for += operator","[bigint]"){
  bigint a(145566);
  bigint b(111123);
  a+= b;
 // REQUIRE(a.get_digit(0)==9);
  REQUIRE(a.get_digit(1)==8);
  REQUIRE(a.get_digit(2)==6);
  REQUIRE(a.get_digit(3)==6);
  REQUIRE(a.get_digit(4)==5);
  REQUIRE(a.get_digit(5)==2);
  bigint c(123);
  bigint d(12);
  c+= d;
  REQUIRE(c.get_digit_count()==3);
  REQUIRE(c.get_digit(0)==5);
  REQUIRE(c.get_digit(1)==3);
  REQUIRE(c.get_digit(2)==1);
  
  bigint e(12);
  bigint f(54626);
  e+=f;
  REQUIRE(e.get_digit_count()==5);
  REQUIRE(e.get_digit(0)==8);
  REQUIRE(e.get_digit(1)==3);
  REQUIRE(e.get_digit(2)==6);
  REQUIRE(e.get_digit(3)==4);
  REQUIRE(e.get_digit(4)==5);
  
  bigint g(9999);
  bigint h(1);
  g+=h;
  REQUIRE(g.get_digit_count()==5);
  REQUIRE(g.get_digit(0)==0);
  REQUIRE(g.get_digit(1)==0);
  REQUIRE(g.get_digit(2)==0);
  REQUIRE(g.get_digit(3)==0);
  REQUIRE(g.get_digit(4)==1);
  bigint i(9999);
  bigint j(1);
  j+=i;
  REQUIRE(j.get_digit_count()==5);
  REQUIRE(j.get_digit(0)==0);
  REQUIRE(j.get_digit(1)==0);
  REQUIRE(j.get_digit(2)==0);
  REQUIRE(j.get_digit(3)==0);
  REQUIRE(j.get_digit(4)==1);
  
  bigint k(9999);
  bigint l(9999);
  k+=l;
  REQUIRE(k.get_digit_count()==5);
  REQUIRE(k.get_digit(0)==8);
  REQUIRE(k.get_digit(1)==9);
  REQUIRE(k.get_digit(2)==9);
  REQUIRE(k.get_digit(3)==9);
  REQUIRE(k.get_digit(4)==1);
  
  bigint m;
  bigint n(9864);
  m+=n;
 // REQUIRE(m.get_digit_count()==4);
  REQUIRE(m.get_digit(0)==4);
  REQUIRE(m.get_digit(1)==6);
  REQUIRE(m.get_digit(2)==8);
  REQUIRE(m.get_digit(3)==9);
  
  
  
}

TEST_CASE("multipilcation *=","[bigint]"){
    bigint a(1);
    bigint b(2);
    b*=a;
    REQUIRE(b.get_digit_count()==1);
    REQUIRE(b.get_digit(0)==2);
    bigint c(1234);
    bigint d(45);
    c*=d;
    REQUIRE(c.get_digit_count()==5);
    REQUIRE(c.get_digit(0)==0);
    REQUIRE(c.get_digit(1)==3);
    REQUIRE(c.get_digit(2)==5);
    REQUIRE(c.get_digit(3)==5);
    REQUIRE(c.get_digit(4)==5);
}

TEST_CASE("Bigger multiplications","[bigint]"){
    uint8_t a[]={9,9,9,9,9,9,9,9,9,9,9};
    uint8_t b[]={4,5,6,7,8,9,1,3,4,5};
    bigint f(99);
    bigint c(a,11,false);
    bigint d (b,10,false);
    c*=f; 
    REQUIRE(c.get_digit_count()==13);
    REQUIRE(c.get_digit(0)==1);
    REQUIRE(c.get_digit(1)==0);
    REQUIRE(c.get_digit(2)==9);
    REQUIRE(c.get_digit(3)==9);
    REQUIRE(c.get_digit(4)==9);
    REQUIRE(c.get_digit(5)==9);
    REQUIRE(c.get_digit(6)==9);
    REQUIRE(c.get_digit(7)==9);
    REQUIRE(c.get_digit(8)==9);
    REQUIRE(c.get_digit(9)==9);
    REQUIRE(c.get_digit(10)==9);
    REQUIRE(c.get_digit(11)==8);
    REQUIRE(c.get_digit(12)==9);
   
}

TEST_CASE("subtraction","[bigint]"){
    bigint a(321);
    bigint b(2);
    a-=b;
    REQUIRE(a.get_digit(0)==9);
    REQUIRE(a.get_digit(1)==1);
    REQUIRE(a.get_digit(2)==3);
    bigint e(1000000);
    bigint f(9);
    e-=f;
    REQUIRE( e.get_digit(0)==1);
    REQUIRE(e.get_digit(1)==9);
    REQUIRE(e.get_digit(2)==9);
    REQUIRE(e.get_digit(3)==9);
    REQUIRE(e.get_digit(4)==9);
    REQUIRE(e.get_digit(5)==9);
    REQUIRE(e.get_digit_count()==6);
    
}

TEST_CASE("+ operator","[bigint]"){
    bigint a(99345669);
    bigint c(11111111);
    bigint d= a+c;
    REQUIRE(d.get_digit_count()==9);
    REQUIRE(d.get_digit(0)==0);
    REQUIRE(d.get_digit(1)==8);
    REQUIRE(d.get_digit(2)==7);
    REQUIRE(d.get_digit(3)==6);
    REQUIRE(d.get_digit(4)==5);
    REQUIRE(d.get_digit(5)==4);
    REQUIRE(d.get_digit(6)==0);
    REQUIRE(d.get_digit(7)==1);
    REQUIRE(d.get_digit(8)==1);
}

TEST_CASE("- operator","[bigint]"){
    bigint a(1000000);
    bigint b(2);
    bigint c = b-a;
    REQUIRE(c.get_digit_count()==6);
    REQUIRE(c.get_digit(0)==8);
    REQUIRE(c.get_digit(1)==9);
    REQUIRE(c.get_digit(2)==9);
    REQUIRE(c.get_digit(3)==9);
    REQUIRE(c.get_digit(4)==9);
    REQUIRE(c.get_digit(5)==9);
}
 

TEST_CASE("giving to opposite signs to addition","[bigint]"){
    bigint a(1000000);
    bigint b(-2); 
    a+=b;
    REQUIRE(a.get_digit_count()==6);
    REQUIRE(a.get_digit(0)==8);
    REQUIRE(a.get_digit(1)==9);
    REQUIRE(a.get_digit(2)==9);
    REQUIRE(a.get_digit(3)==9);
    REQUIRE(a.get_digit(4)==9);
    REQUIRE(a.get_digit(5)==9);
    REQUIRE(a.is_negative()==false);
}

TEST_CASE("giving two negative numbers","[bigint]"){
    bigint d(-99345669);
    bigint c(-11111111);
     d+=c;
    REQUIRE(d.get_digit_count()==9);
    REQUIRE(d.get_digit(0)==0);
    REQUIRE(d.get_digit(1)==8);
    REQUIRE(d.get_digit(2)==7);
    REQUIRE(d.get_digit(3)==6);
    REQUIRE(d.get_digit(4)==5);
    REQUIRE(d.get_digit(5)==4);
    REQUIRE(d.get_digit(6)==0);
    REQUIRE(d.get_digit(7)==1);
    REQUIRE(d.get_digit(8)==1);
    REQUIRE(d.is_negative()==true);
}

TEST_CASE("giving two negative to -=","[bigint]"){
    bigint d(-99345669);
    bigint c(11111111);
    d-=c;
    REQUIRE(d.get_digit_count()==9);
    REQUIRE(d.get_digit(0)==0);
    REQUIRE(d.get_digit(1)==8);
    REQUIRE(d.get_digit(2)==7);
    REQUIRE(d.get_digit(3)==6);
    REQUIRE(d.get_digit(4)==5);
    REQUIRE(d.get_digit(5)==4);
    REQUIRE(d.get_digit(6)==0);
    REQUIRE(d.get_digit(7)==1);
    REQUIRE(d.get_digit(8)==1);
    REQUIRE(d.is_negative()==true);
    
    
    
}

TEST_CASE("multiplication","[bigint]"){
    bigint a(-123);
    bigint b(-1);
    b*=a;
    REQUIRE(b.get_digit(0)==3);
    REQUIRE(b.get_digit(1)==2);
    REQUIRE(b.get_digit(2)==1);
    REQUIRE(b.get_digit_count()==3);
    REQUIRE(b.is_negative()==false);
}


TEST_CASE("multiplication operator *","[bigint]"){
    bigint a(-123);
    bigint b(1);
    bigint c;
    c =a*b;
    REQUIRE(c.get_digit(0)==3);
    REQUIRE(c.get_digit(1)==2);
    REQUIRE(c.get_digit(2)==1);
    REQUIRE(c.get_digit_count()==3);
    REQUIRE(c.is_negative()==true);
}

TEST_CASE("multiplication by zero","[bigint]"){
    bigint a(-123);
    bigint b(0);
    bigint c(1);
    c=b*a;
    REQUIRE(c.get_digit(0)==0);
    REQUIRE(c.get_digit_count()==1);
    REQUIRE(c.is_negative()==false);
    
}

TEST_CASE("<< operator","[bigint]"){
 bigint a;
 std::stringstream ss;

 bigint b(-123);
 ss<<b;
 REQUIRE(ss.str()=="-123");
 
}

TEST_CASE("<< operator for 0","[bigint]"){
 bigint a;
 std::stringstream ss;
 ss<< a;
 REQUIRE(ss.str()=="0");
 
}

TEST_CASE("double -"){
    bigint a(1234);
    bigint b(-6);
    bigint c= a-b;
    REQUIRE(c.get_digit(0)==0);
    REQUIRE(c.get_digit(1)==4);
    REQUIRE(c.get_digit(2)==2);
    REQUIRE(c.get_digit(3)==1);
    REQUIRE(c.get_digit_count()==4);
}

TEST_CASE("adding 0"){
    bigint a(1234);
    bigint b(0);
    bigint c= a-b;
    REQUIRE(c.get_digit(0)==4);
    REQUIRE(c.get_digit(1)==3);
    REQUIRE(c.get_digit(2)==2);
    REQUIRE(c.get_digit(3)==1);
    REQUIRE(c.get_digit_count()==4);
    REQUIRE(c.is_negative()==false);
}



 
 
