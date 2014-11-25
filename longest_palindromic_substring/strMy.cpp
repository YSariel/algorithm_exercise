#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //string t1 = "abababa";
    //string t2 = "aaabbaaa";
    //string t3 = "acacdas";
    string t4 = "acacdasTTaaaTTsa";
    //string t5 = "aaaaaaaa";
    //int n;
    //cin >> n;
    //while(n--){

	    string t = t4;
	    //cin >> t;

	    int tl = t.length();
	    int max_len = 0, is_O = 0,i;
	    int found = 0;

	    if(tl % 2 == 0){
	    	is_O = 1;
	        for(int i = 1; i < tl * 2 - 1; i+=2){
	            //cout << t << endl;
	            t.insert(i, "#");
	        }
	        tl = t.length();
	    }
	    //cout << "t: " << t << endl;
	    int htl = tl / 2;
	    //cout << "htl: " << htl << endl;


	    i = 1;
	    while(t[htl + i] == t[htl - i]){
	    	//cout << "i: " << i << endl;
	    	++i;
	    }
	    if(i == htl + 1){
	    	if(is_O){
	    		max_len = i;
	    		printf("%d\n", max_len);
	    		//cout << max_len << endl;
	    	}else{
	    		max_len = i * 2 - 1;
	    		printf("%d\n", max_len);
	    		//cout << max_len << endl;
	    	}

	    }else{
	    	max_len = i;
			for(i = 1; i < tl / 2; i++){
				//cout << "=====" << i << "=====" << endl;
				int lp = tl / 2 - i;
				int rp = tl / 2 + i;
				int accl = 0, accr = 0;
				while(t[lp + accl] == t[lp - accl])accl++;
				while(t[rp + accr] == t[rp - accr])accr++;
				int tmp = accl > accr ? accl : accr;
				//cout << accl << " " << accr << " " << tmp << " " << max_len << " " << lp << endl;
				if(tmp == lp + 1){
			    	if(is_O){
			    		max_len = tmp > max_len ? tmp : max_len;
			    		printf("%d\n", max_len);//cout << max_len << endl;
			    		found = 1;
			    		break;
			    	}else{
			    		max_len = tmp * 2 - 1 > max_len ? tmp * 2 - 1 : max_len;
			    		printf("%d\n", max_len);//cout << max_len << endl;
			    		found = 1;
			    		break;
			    	}
				}else if(max_len >= lp){
					if(is_O){
			    		max_len = tmp > max_len ? tmp - 1 : max_len;
			    		break;
			    	}
			    	else{
			    		max_len = tmp * 2 - 1 > max_len ? tmp * 2 - 1 : max_len;
			    		break;
			    	}
				}else{
					if(is_O){
			    		max_len = tmp > max_len ? tmp - 1 : max_len;
			    	}
			    	else{
			    		max_len = tmp * 2 - 1 > max_len ? tmp * 2 - 1 : max_len;
			    	}				
				}
			}
	    	if(found == 0 && is_O){
	    		printf("%d\n", max_len);
	    		//cout << max_len << endl;
	    	}else if(found == 0){
	    		max_len = max_len * 2 - 1;
	    		printf("%d\n", max_len);
	    		//cout << "out is_J: " << max_len << endl;
	    	}
	    }
	//}

}