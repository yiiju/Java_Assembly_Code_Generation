void main(){
	int a = 20;
    if (a == 40){
        print("a is equal to 40");
		int b = 4;
		if(b == 4) {
			print(b);
		}
		else if(b == 7) {
			int c = 9;
			print(c);
		}
    }
    else if (a > 40){
        print("a is larger than 40");
		if(a > 50) {
			print("a > 50");
		}
    }
     else{
        print(666);
    }

	if(a == 30) {
		print("a == 30");
	}
	else if(a == 20){
		if(a == 20) {
			print("a == 20");
		}
		else {
			print("fail");
		}
		print("succ");
	}
	return;
}
