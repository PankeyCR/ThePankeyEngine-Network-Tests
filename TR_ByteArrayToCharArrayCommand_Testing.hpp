
#ifndef TR_ByteArrayToCharArrayCommand_Testing_hpp
	#define TR_ByteArrayToCharArrayCommand_Testing_hpp
	
	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "ByteArrayToCharArrayCommand.hpp"

	namespace pankey{

		namespace Network{
			Base::TestResult<String> g_BTC_result;

			void TestBTCCommand_C(const Base::ByteArray& a_ip, const Base::CharArray& a_array){
				String i_message = a_array.c_str().get();
				g_BTC_result.expecting(i_message);
			}

			void TestBTCCommand_AC(int& a_app, const Base::ByteArray& a_ip, const Base::CharArray& a_array){
				String i_app = String(a_app);
				String i_message = a_array.c_str().get();
				g_BTC_result.expecting(i_app);
				g_BTC_result.expecting(i_message);
			}

			void TestBTCCommand_A_C(const Base::ByteArray& a_ip, const Base::ArrayRawList<Base::CharArray>& a_array){
				Base::CharArray i_char_1 = a_array.getByIndex(0);
				Base::CharArray i_char_2 = a_array.getByIndex(1);
				String i_message_1 = i_char_1.c_str().get();
				String i_message_2 = i_char_2.c_str().get();
				g_BTC_result.expecting(i_message_1);
				g_BTC_result.expecting(i_message_2);
			}

			void TestBTCCommand_A_AC(int& a_app, const Base::ByteArray& a_ip, const Base::ArrayRawList<Base::CharArray>& a_array){
				String i_app = String(a_app);
				Base::CharArray i_char_1 = a_array.getByIndex(0);
				Base::CharArray i_char_2 = a_array.getByIndex(1);
				String i_message_1 = i_char_1.c_str().get();
				String i_message_2 = i_char_2.c_str().get();
				g_BTC_result.expecting(i_app);
				g_BTC_result.expecting(i_message_1);
				g_BTC_result.expecting(i_message_2);
			}
			
			Base::TestResult<String> TR_ByteArrayToCharArrayCommand_Testing_1(){
				g_BTC_result.clear();
				
				ByteArrayToCharArrayCommand<int> i_command;
				i_command.add(TestBTCCommand_C);

				int i_app = 15;
				Base::ByteArray i_ip = Base::createArrayPointer<Byte>(192,168,1,110);
				Base::ByteArray i_array;
				i_array.add('t');
				i_array.add('e');
				i_array.add('s');
				i_array.add('t');
				i_array.add('_');
				i_array.add('1');

				i_command.execute(i_app, i_ip, i_array);

				g_BTC_result.assertExpectation("test_1");

				Base::TestResult<String> i_result = g_BTC_result;
				g_BTC_result.clear();
				
				return i_result;
			}
			
			Base::TestResult<String> TR_ByteArrayToCharArrayCommand_Testing_2(){
				g_BTC_result.clear();
				
				ByteArrayToCharArrayCommand<int> i_command;
				i_command.add(TestBTCCommand_AC);

				int i_app = 15;
				Base::ByteArray i_ip = Base::createArrayPointer<Byte>(192,168,1,110);
				Base::ByteArray i_array;
				i_array.add('t');
				i_array.add('e');
				i_array.add('s');
				i_array.add('t');
				i_array.add('_');
				i_array.add('2');

				i_command.execute(i_app, i_ip, i_array);

				g_BTC_result.assertExpectation("15");
				g_BTC_result.assertExpectation("test_2");

				Base::TestResult<String> i_result = g_BTC_result;
				g_BTC_result.clear();
				
				return i_result;
			}
			
			Base::TestResult<String> TR_ByteArrayToCharArrayCommand_Testing_3(){
				g_BTC_result.clear();
				
				ByteArrayToCharArrayCommand<int> i_command;
				i_command.add(TestBTCCommand_A_C);

				int i_app = 15;
				Base::ByteArray i_ip = Base::createArrayPointer<Byte>(192,168,1,110);
				Base::ByteArray i_array;
				i_array.add('t');
				i_array.add('e');
				i_array.add('s');
				i_array.add('t');
				i_array.add('_');
				i_array.add('3');
				i_array.add(' ');
				i_array.add('e');
				i_array.add('x');
				i_array.add('i');
				i_array.add('t');

				i_command.execute(i_app, i_ip, i_array);

				g_BTC_result.assertExpectation("test_3");
				g_BTC_result.assertExpectation("exit");

				Base::TestResult<String> i_result = g_BTC_result;
				g_BTC_result.clear();
				
				return i_result;
			}
			
			Base::TestResult<String> TR_ByteArrayToCharArrayCommand_Testing_4(){
				g_BTC_result.clear();
				
				ByteArrayToCharArrayCommand<int> i_command;
				i_command.add(TestBTCCommand_A_AC);

				int i_app = 15;
				Base::ByteArray i_ip = Base::createArrayPointer<Byte>(192,168,1,110);
				Base::ByteArray i_array;
				i_array.add('t');
				i_array.add('e');
				i_array.add('s');
				i_array.add('t');
				i_array.add('_');
				i_array.add('3');
				i_array.add(' ');
				i_array.add('e');
				i_array.add('x');
				i_array.add('i');
				i_array.add('t');

				i_command.execute(i_app, i_ip, i_array);

				g_BTC_result.assertExpectation("15");
				g_BTC_result.assertExpectation("test_3");
				g_BTC_result.assertExpectation("exit");

				Base::TestResult<String> i_result = g_BTC_result;
				g_BTC_result.clear();
				
				return i_result;
			}
			
			void TR_ByteArrayToCharArrayCommand_Testing(Base::TestRunner<String>& a_test_runner){
				a_test_runner.add("ByteArrayToCharArrayCommand Base::CharArray", TR_ByteArrayToCharArrayCommand_Testing_1);
				a_test_runner.add("ByteArrayToCharArrayCommand int&,Base::CharArray", TR_ByteArrayToCharArrayCommand_Testing_2);
				a_test_runner.add("ByteArrayToCharArrayCommand Base::ArrayRawList<Base::CharArray>", TR_ByteArrayToCharArrayCommand_Testing_3);
				a_test_runner.add("ByteArrayToCharArrayCommand int&,Base::ArrayRawList<Base::CharArray>", TR_ByteArrayToCharArrayCommand_Testing_4);
			}

		}

	}

#endif