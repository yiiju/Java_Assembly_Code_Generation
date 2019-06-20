void foo() {
	print("in foo");
	return;
}
void main() {
	int a = 0;
	foo();
	print(a); // 0
	a = 2 + 6 / 3;
	print(a); // 4
	int b = a++;
	print(b); // 4
	if (a == b) { // not in
		if(a > 2) { // in
			print("a > 2");
		}
		else {
			print("a <= 2");
		}
	}
	else if(b >= 5) {
		print("b >= 5");
	}
	else if(b < 5) {
		if(b != 2) {
			print("b != 2");
		}
		int c = 4;
		print("c is");
		print(c);
		int d = 4;
		while(d < 7){
			d++;
			//d = 10;
			print(d);
		}
		if(c > 8) {
			print("impossible");
		}
		else { // in
			print("c less than 8");
		}
	}
	int c = 9;
	int f = 3;
	c--;
	print(c);
	if(f > c) {
		print("impossible");
	}
	while(c > 5) {
		c--;
		print(c);
	}
	print("succ");
	return;
}
