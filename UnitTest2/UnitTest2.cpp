#include "pch.h"
#include "CppUnitTest.h"
#include "main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// ��������һ����Ԫ�ӷ���ʽ
		TEST_METHOD(TestMethod1)
		{
			BinaryOperation* a = new AdditionOperation();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
			Assert::IsTrue(a->getLaw());
		}

		// ��������һ����Ԫ������ʽ
		TEST_METHOD(TestMethod2) {
			BinaryOperation* a = new SubtractOperation();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
			Assert::IsTrue(a->getLaw());
		}

		// ��������һ����Ԫ�˷���ʽ
		TEST_METHOD(TestMethod3) {
			BinaryOperation* a = new MutiplicationOperation();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
			Assert::IsTrue(a->getLaw());
		}

		// ��������һ����Ԫ������ʽ
		TEST_METHOD(TestMEthod4) {
			BinaryOperation* a = new DivisionOperation();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
			Assert::IsTrue(a->getLaw());
		}

		// ��������һ�������ʽ
		TEST_METHOD(TestMEthod5) {
			BinaryOperation* a = new MixtureOperation();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
		}

		// ��������һ����ϴ����ŵ���ʽ
		TEST_METHOD(TestMEthod6) {
			BinaryOperation* a = new MixedOperationWithBracket();
			a->createOperation();
			string s = a->getOperation();
			Assert::AreEqual(a->getValue(), a->calculate());
			Assert::IsTrue(a->checkIsLaw(s));
		}

		// ������ȷ��������һ����Ԫ�ӷ���ʽ
		TEST_METHOD(TestMEthod7) {
			AdditionOperation a("1+1");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 2);
		}

		// ���Դ���������һ����Ԫ�ӷ���ʽ
		TEST_METHOD(TestMEthod8) {
			AdditionOperation a("1+");
			Assert::IsFalse(a.getLaw());
		}

		// ������ȷ��������һ����Ԫ������ʽ
		TEST_METHOD(TestMEthod9) {
			SubtractOperation a("31-1");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 30);
		}

		// ���Դ���������һ����Ԫ������ʽ
		TEST_METHOD(TestMEthod10) {
			SubtractOperation a("31-10-");
			Assert::IsFalse(a.getLaw());
		}

		// ������ȷ��������һ����Ԫ�˷���ʽ
		TEST_METHOD(TestMEthod11) {
			MutiplicationOperation a("9 * 10");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 90);
		}

		// ���Դ���������һ����Ԫ�˷���ʽ
		TEST_METHOD(TestMEthod12) {
			MutiplicationOperation a("9 * 12��");
			Assert::IsFalse(a.getLaw());
		}

		// ������ȷ��������һ����Ԫ������ʽ
		TEST_METHOD(TestMEthod13) {
			DivisionOperation a("9 / 3");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 3);
		}

		// ���Դ���������һ����Ԫ������ʽ
		TEST_METHOD(TestMEthod14) {
			DivisionOperation a("9 // 3");
			Assert::IsFalse(a.getLaw());
		}

		// ������ȷ��������һ�������ʽ
		TEST_METHOD(TestMEthod15) {
			MixtureOperation a("90+2*10/5-4");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 90);
		}

		// ������ȷ��������һ�������ʽ
		TEST_METHOD(TestMEthod16) {
			MixtureOperation a("1+10+(10* 3) - 1");
			Assert::IsTrue(a.getLaw());
			Assert::AreEqual(a.getValue(), 40);
		}

		// ���Դ���������һ�������ʽ
		TEST_METHOD(TestMEthod17) {
			MixtureOperation a("1+1+(2+1)-1)");
			Assert::IsFalse(a.getLaw());
		}

		// �����Ϊ����
		TEST_METHOD(TestMEthod18) {
			MixtureOperation a("40-41");
			Assert::IsFalse(a.getLaw());
		}

		// �����ΪС��
		TEST_METHOD(TestMEthod19) {
			MixtureOperation a("8/3");
			Assert::IsFalse(a.getLaw());
		}

		// ��������и�������ʹ���Ϊ��
		TEST_METHOD(TestMEthod20) {
			MixtureOperation a("10+20-10*4+100");
			Assert::IsFalse(a.getLaw());
		}

		// ���������С�����֣���ʹ�������С��
		TEST_METHOD(TestMEthod21) {
			MixtureOperation a("10/20 + 3/2");
			Assert::IsFalse(a.getLaw());
		}


		// ��������һ�꼶��ϰ��
		TEST_METHOD(TestMEthod22) {
			Equation* a = new Equation();
			a->createSumEquation(50, 0, 1);
			a->printEquation();
		}

		// �������ɶ��꼶��ϰ��
		TEST_METHOD(TestMEthod23) {
			Equation* a = new Equation();
			a->createSumEquation(50, 0, 2);
			a->printEquation();
		}

		// �����������꼶��ϰ��
		TEST_METHOD(TestMEthod24) {
			Equation* a = new Equation();
			a->createSumEquation(50, 0, 3);
			a->printEquation();
		}

		// �����������꼶��ϰ��
		TEST_METHOD(TestMEthod25) {
			Equation* a = new Equation();
			a->createSumEquation(50, 0, 4);
			a->printEquation();
		}

		// �����������꼶��ϰ��
		TEST_METHOD(TestMEthod26) {
			Equation* a = new Equation();
			a->createSumEquation(50, 5, 5);
			a->printEquation();
		}

		// �����������꼶��ϰ��
		TEST_METHOD(TestMEthod27) {
			Equation* a = new Equation();
			a->createSumEquation(50, 10, 6);
			a->printEquation();
		}

		// �������ɴ�����ʽ
		TEST_METHOD(TestMEthod28) {
			Equation* a = new Equation();
			a->createSumEquation(1000000, 10000, 6);
			a->printEquation();
		}
	};
}
