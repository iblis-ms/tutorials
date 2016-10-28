#include <iostream>
#include <benchmark/benchmark.h>
#include <boost/move/move.hpp>
#include <boost/smart_ptr.hpp>

const int kRangeMultiplier = 2;
const int kRangeMin = 1;
const int kRangeMax = 1 << 15;

class Base
{
BOOST_COPYABLE_AND_MOVABLE(Base)

public:

  Base(int aN)
      :
        iN(aN)
  {
    iBaseField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iBaseField[i] = i;
    }
  }

  Base(const Base& aBase)
      :
        iN(aBase.iN)
  {
    iBaseField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iBaseField[i] = aBase.iBaseField[i];
    }
  }

  Base(BOOST_RV_REF(Base)base) : iN(base.iN), iBaseField(base.iBaseField)
  {
    base.iBaseField = 0;
  }

  Base& operator=(BOOST_COPY_ASSIGN_REF(Base) aBase)
  {
    delete[] iBaseField;
    iN = aBase.iN;
    iBaseField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iBaseField[i] = aBase.iBaseField[i];
    }
    return *this;
  }

  Base& operator=(BOOST_RV_REF(Base) aBase)
  {
    delete[] iBaseField;

    iN = boost::move(aBase.iN);
    iBaseField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iBaseField[i] = boost::move(aBase.iBaseField[i]);
    }
    aBase.iBaseField = 0;
    return *this;
  }

  ~Base()
  {
    delete[] iBaseField;
  }

private:

  int iN;
  int *iBaseField;

};

class Member
{
public:

BOOST_COPYABLE_AND_MOVABLE(Member)

public:

  Member(int aN)
      :
        iN(aN)
  {
    iMemberField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iMemberField[i] = i;
    }
  }

  Member(const Member& aMember)
      :
        iN(aMember.iN)
  {
    iMemberField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iMemberField[i] = aMember.iMemberField[i];
    }
  }

  Member(BOOST_RV_REF(Member)aMember) : iN(aMember.iN), iMemberField(aMember.iMemberField)
  {
    aMember.iMemberField = 0;
  }

  Member& operator=(BOOST_COPY_ASSIGN_REF(Member) aMember)
  {
    delete[] iMemberField;
    iN = aMember.iN;
    iMemberField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iMemberField[i] = aMember.iMemberField[i];
    }
    return *this;
  }

  Member& operator=(BOOST_RV_REF(Member) aMember)
  {
    delete[] iMemberField;

    iN = boost::move(aMember.iN);
    iMemberField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iMemberField[i] = boost::move(aMember.iMemberField[i]);
    }
    aMember.iMemberField = 0;
    return *this;
  }

  ~Member()
  {
    delete[] iMemberField;
  }

private:
  int iN;
  int* iMemberField;
};

class Derivative : public Base
{
BOOST_COPYABLE_AND_MOVABLE(Derivative)

public:

  Derivative(int aN)
      :
        Base(aN),
        iMember(aN),
        iBigMember(100 * aN),
        iN(aN)
  {
    iDerivativeField1 = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField1[i] = i;
    }
  }

  Derivative(const Derivative& aDerivative)
      :
        Base(aDerivative),
        iMember(aDerivative.iMember),
        iBigMember(aDerivative.iBigMember),
        iN(aDerivative.iN)
  {
    iDerivativeField1 = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField1[i] = aDerivative.iDerivativeField1[i];
    }
  }

  Derivative(BOOST_RV_REF(Derivative)aDerivative)
      :
         Base(BOOST_MOVE_BASE(Base, aDerivative)),
         iMember(boost::move(aDerivative.iMember)),
         iBigMember(boost::move(aDerivative.iBigMember)),
         iN(aDerivative.iN),
         iDerivativeField1(aDerivative.iDerivativeField1)
  {
    aDerivative.iDerivativeField1 = 0;
  }

  Derivative& operator=(BOOST_COPY_ASSIGN_REF(Derivative) aDerivative)
  {
    Base::operator=(aDerivative);

    delete[] iDerivativeField1;
    iMember = aDerivative.iMember;
    iBigMember = aDerivative.iBigMember;
    iN = aDerivative.iN;
    iDerivativeField1 = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField1[i] = aDerivative.iDerivativeField1[i];
    }
    return *this;
  }

  Derivative& operator=(BOOST_RV_REF(Derivative) aDerivative)
  {
    Base::operator=(BOOST_MOVE_BASE(Base, aDerivative));

    delete[] iDerivativeField1;

    iMember = boost::move(aDerivative.iMember);
    iBigMember = boost::move(aDerivative.iBigMember);
    iN = boost::move(aDerivative.iN);
    iDerivativeField1 = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField1[i] = boost::move(aDerivative.iDerivativeField1[i]);
    }
    aDerivative.iDerivativeField1 = 0;
    return *this;
  }

  ~Derivative()
  {
    delete[] iDerivativeField1;
  }

private:

  int iN;
  Member iMember;
  Member iBigMember;
  int* iDerivativeField1;
};

////////////////////////////////////////////////////////////////////////////////
boost::shared_ptr<Derivative> copy(Derivative& aItem)
{
  return boost::shared_ptr<Derivative>(new Derivative(aItem));
}

void Boost_Benchmark_copy(benchmark::State& aState)
{
  const int size = aState.range(0);
  Derivative item(size);
  while (aState.KeepRunning())
  {
    boost::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = copy(item));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Boost_Benchmark_copy)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();
///
boost::shared_ptr<Derivative> rvalueConstructor(Derivative& aItem)
{
  return boost::shared_ptr<Derivative>(new Derivative(boost::move(aItem)));
}

void Boost_Benchmark_rvalueConstructor(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    aState.PauseTiming(); // turn off timer
    Derivative item(size);
    aState.ResumeTiming(); // turn on timer
    boost::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = rvalueConstructor(item));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Boost_Benchmark_rvalueConstructor)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();
////
boost::shared_ptr<Derivative> rvalueConstructor(int aSize)
{
  return boost::shared_ptr<Derivative>(new Derivative(Derivative(aSize)));
}

void Boost_Benchmark_rvalueConstructorInitialization(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    boost::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = rvalueConstructor(size));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Boost_Benchmark_rvalueConstructorInitialization)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////

// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN()
;

