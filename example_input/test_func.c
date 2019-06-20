bool v = true;
int e = 6;
float r = 0.3;
string b = "Hi";
void fun(int a);
void fun(int a) {
	int b = 3;
	print(a);
	return;
}
void fun2(int a);
void fun2(int a) {
	return;
}
float func3();
float func3() {
	return 1.4;
}
void func4(int s, string f) {
	print(f);
	return;
}
void func4(int s, string f);
float func5() {
	print("in 5");
	return 8.3;
}
float func5();
void main() {
	int a = 1;
	int d = a + 6;
	func5();
	print(d);
	func4(d, "hihi");
	fun(3);
    return;
}
