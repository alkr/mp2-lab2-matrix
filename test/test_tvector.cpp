#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(10);
  for (int i=0;i<10;i++)
    v[i]=i;
  TVector<int> a(v);
  EXPECT_EQ(a,v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
   TVector<int> v(10);
  v[5]=1;
  TVector<int> a(v);
  a[0]=2;
  EXPECT_NE(v, a);
}

TEST(TVector, can_get_size)
{
  TVector<int>v(4);

  EXPECT_EQ(4,v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(5,1);

  EXPECT_EQ(1,v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(5);
  v[0]=1;

  EXPECT_EQ(1,v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[-5]=5);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(10);
  ASSERT_ANY_THROW(v[11]=5);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(10);
  ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
   TVector<int> v(10), a(10);
  for (int i=0;i<10;i++)
    v[i]=i+5;
  a=v;
  EXPECT_EQ(v,a);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(5),a(3);
  for (int i=0;i<5; i++)
  v[i]=5;
  a=v;
  EXPECT_EQ(v.GetSize(),a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(5), a(3);
  for (int i=0;i<5; i++)
   v[i]=5;
  a=v;
  EXPECT_EQ(v,a);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(10),a(10);
  for (int i=0; i<10; i++)
    v[i]=5;
  a=v;
  EXPECT_EQ(true, a==v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
   TVector<int> v(10);
  for (int i=0; i<10; i++)
    v[i]=5;
  EXPECT_EQ(true, v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(10),a(1);
  EXPECT_EQ(false, a==v);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v(10),a(10);
  for (int i=0; i<10; i++)
	  v[i]=i;
  for (int i=0;i<10; i++)
	  a[i]=i+2;
  EXPECT_EQ(a, v+2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(10), a(10);
  for (int i=0; i<10; i++)
	  v[i]=i;
  for (int i = 0; i < 10; i++)
	  a[i]=i-2;
  EXPECT_EQ(a, v-2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
   TVector<int> v(10),a(10);
  for (int i=0; i<10; i++)
	  v[i]=1;
  for (int i=0; i<10; i++)
	  a[i]=2;
  EXPECT_EQ(a, v*2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(10), a(10), b(10);
  for (int i=0; i<10; i++) 
  {
    v[i]=5;
    a[i]=3;
	b[i]=8;
  }
  EXPECT_EQ(b, a + v);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(10), a(8);
  ASSERT_ANY_THROW(a+v);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(10), a(10), b(10);
  for (int i =0; i<10; i++) 
  {
    v[i]=5;
    a[i]=3;
	b[i]=-2;
  }
  EXPECT_EQ(b, a-v);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(10), a(8);
  ASSERT_ANY_THROW(a-v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(10),a(10);
  for (int i=0; i<10; i++) 
  {
    v[i]=1;
    a[i]=2;
  }
  EXPECT_EQ(20, a*v);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(10), a(8);
  ASSERT_ANY_THROW(a * v);
}