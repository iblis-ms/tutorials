#include <iostream>
#include <vector>
#include <benchmark/benchmark.h>
#include <memory>

constexpr int kRangeMultiplier = 2;
constexpr int kRangeMin = 1;
constexpr int kRangeMax = 1 << 15;


class Base
{

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

  Base(Base&& aBase) : iN(aBase.iN), iBaseField(aBase.iBaseField)
  {
    aBase.iBaseField = 0;
  }

  Base& operator=(Base& aBase)
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

  Base& operator=(Base&& aBase)
  {
    delete[] iBaseField;

    iN = std::move(aBase.iN);
    iBaseField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iBaseField[i] = std::move(aBase.iBaseField[i]);
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

  Member(Member&& base) : iN(base.iN), iMemberField(base.iMemberField)
  {
    base.iMemberField = 0;
  }

  Member& operator=(Member& aMember)
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

  Member& operator=(Member&& aMember)
  {
    delete[] iMemberField;

    iN = std::move(aMember.iN);
    iMemberField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iMemberField[i] = std::move(aMember.iMemberField[i]);
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

public:

  Derivative(int aN)
      :
        Base(aN),
        member(aN),
        iBigMember(100 * aN),
        iN(aN)
  {
    iDerivativeField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField[i] = i;
    }
  }

  Derivative(const Derivative& aDerivative)
      :
        Base(aDerivative),
        member(aDerivative.member),
        iBigMember(aDerivative.iBigMember),
        iN(aDerivative.iN)
  {
    iDerivativeField = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField[i] = aDerivative.iDerivativeField[i];
    }
  }

  Derivative(Derivative&& aDerivative)
      :
         Base(std::move(aDerivative)),
         member(std::move(aDerivative.member)),
         iBigMember(std::move(aDerivative.iBigMember)),
         iN(aDerivative.iN),
         iDerivativeField(aDerivative.iDerivativeField)
  {
    aDerivative.iDerivativeField = 0;
  }

  Derivative& operator=(Derivative aDerivative)
  {
    Base::operator=(aDerivative);

    delete[] iDerivativeField;
    member = aDerivative.member;
    iBigMember = aDerivative.iBigMember;
    iN = aDerivative.iN;
    iDerivativeField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField[i] = aDerivative.iDerivativeField[i];
    }
    return *this;
  }

  Derivative& operator=(Derivative&& aDerivative)
  {
    Base::operator=(std::move(aDerivative));

    delete[] iDerivativeField;

    member = std::move(aDerivative.member);
    iBigMember = std::move(aDerivative.iBigMember);
    iN = std::move(aDerivative.iN);
    iDerivativeField = new int[iN];

    for (int i = 0; i < iN; ++i)
    {
      iDerivativeField[i] = std::move(aDerivative.iDerivativeField[i]);
    }
    aDerivative.iDerivativeField = 0;
    return *this;
  }

  ~Derivative()
  {
    delete[] iDerivativeField;
  }

private:

  int iN;
  Member member;
  Member iBigMember;
  int* iDerivativeField;
};

////////////////////////////////////////////////////////////////////////////////
std::shared_ptr<Derivative> copy(Derivative& aItem)
{
  return std::shared_ptr<Derivative>(new Derivative(aItem));
}

void Cpp11_Benchmark_copy(benchmark::State& aState)
{
  const int size = aState.range(0);
  Derivative item(size);
  while (aState.KeepRunning())
  {
    std::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = copy(item));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Cpp11_Benchmark_copy)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();
///
std::shared_ptr<Derivative> rvalueConstructor(Derivative& aItem)
{
  return std::shared_ptr<Derivative>(new Derivative(std::move(aItem)));
}

void Cpp11_Benchmark_rvalueConstructor(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    aState.PauseTiming(); // turn off timer
    Derivative item(size);
    aState.ResumeTiming(); // turn on timer
    std::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = rvalueConstructor(item));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Cpp11_Benchmark_rvalueConstructor)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();
////
std::shared_ptr<Derivative> rvalueConstructor(int aSize)
{
  return std::shared_ptr<Derivative>(new Derivative(Derivative(aSize)));
}

void Cpp11_Benchmark_rvalueConstructorInitialization(benchmark::State& aState)
{
  const int size = aState.range(0);
  while (aState.KeepRunning())
  {
    std::shared_ptr<Derivative> ptr;
    benchmark::DoNotOptimize(ptr = rvalueConstructor(size));
  }
  aState.SetComplexityN(size);
}

BENCHMARK(Cpp11_Benchmark_rvalueConstructorInitialization)->RangeMultiplier(kRangeMultiplier)->Range(kRangeMin, kRangeMax)->Complexity();

////////////////////////////////////////////////////////////////////////////////
//                                    MAIN                                    //
////////////////////////////////////////////////////////////////////////////////

// Google Benchmark has a special macro that creates main method.
BENCHMARK_MAIN();
