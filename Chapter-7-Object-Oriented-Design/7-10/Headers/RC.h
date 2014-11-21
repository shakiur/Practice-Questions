#ifndef RC_H
#define RC_H

// Reference Counter
class RC {
	int count;

	public:
		RC():count(0){}

		void addRef(){
			count++;
		}

		int release(){
			return --count;
		}

};

#endif