//Ex code 
//c�OP0,P1���@��resource  
//c=0
//����c=c+1 �A����c=c-1 �̫�c���ӵ���0

P0 // c=c+1
{
	load r5 , c;
	addi r5, r5, 1;
	store r5, c;
}
P1 // c=c-1
{
	load r6 , c;
	addi r6, r6, -1;
	store r6, c;
}
//instruction �i�઺���|
load r5, c; // r5=0
load r6, c; // r6=0
addi r5, r5, 1; // r5=1
addi r6, r6, -1; // r6=-1
store r5, c; // c=1
store r6, c; // c=-1


//Ex code
//Pi�O��e��process Pj�O�P�ɰ��檺�t�~�@��process
bool flag[2] = { false };
int turn;

while (1)
{
	flag[i] = true;
	turn = j;
	while (flag[j] && turn == j);
	/*cs*/
	flag[i] = false;
	/*rs*/
}


//Ex code
bool flag[2] = { false };
int turn;

while(1) // process 0 (i = 0, j = 1)
{
	flag[i] = true;
	turn = j;
	while (flag[j] && turn == j);
	/*cs*/
	flag[i] = false;
	/*rs*/
}

while(1) // process 1 (i = 1, j = 0)
{
	turn = j;
	flag[i] = true;
	while (flag[j] && turn == j);
	/*cs*/
	flag[i] = false;
	/*rs*/
}

//instruction �i�઺���|
flag[0] = true; // P0
turn = 0; // P1
turn = 1; // P0
flag[1] = true; // P1
while (flag[1] && turn == 1); // P0 �L��loop
while (flag[0] && turn == 0);
	//�U��

class Monitor
{
public:
	class condition
	{
	public:
		condition() { S = 1; };
		condition(int n) { S = n; };
		~condition() {};
		wait() {
			S--;
			if (S < 0)
			{
				Queue.push(this process);
				sleep();
			}
		};
		signal() {
			S++;
			if (S->value <= 0) {
				wakeup(Queue.pop());
			}
		};
	private:
		int S;
		Queue<process> list;
	};
	Monitor() {};
	~Monitor() {};
	virtual init();
private:
	
};

Monitor monitor_name
{
	// �@��resource�ŧi

	// operations
	pro1() { ... }
	pro2() { ... }

	// ��l��
	init() { ... }
};

class Mutex
{
public:
	Mutex() {};
	~Mutex() {};
	wait() {
		while (!available);
		available = false;
	};
	signal() {
		available = true;
	};
private:
	bool available = true;
};

Mutex lock; // mutex
while (1)
{
	lock.wait();
	/*cs*/
	lock.signal();
	/*rs*/
};

class Semaphore
{
public:
	Semaphore() {};
	~Semaphore() {};
	set_maxn(int n) { S = n };
	wait() {
		while (S <= 0);
		S--;
	};
	signal() {
		S++;
	};
private:
	int S;
};

Semaphore lock; // Semaphore
while (1)
{
	lock.set_maxn(num);
	lock.wait();
	/*cs*/
	lock.signal();
	/*rs*/
};

class condition
{
public:
	condition() { S = 1; };
	condition(int n) { S = n; };
	~condition() {};
	wait() {
		S--;
		if (S < 0)
		{
			Queue.push(this process);
			sleep();
		}
	};
	signal() {
		S++;
		if (S->value <= 0) {
			wakeup(Queue.pop());
		}
	};
private:
	int S;
	Queue<process> list;
};


monitor ResourceAllocator
{
	boolean busy;
	condition x;
	void acquire(int time) {
		if (busy)
			x.wait(time);
		busy = true;
	}
	void release() {
		busy = false;
		x.signal();
	}
	initialization code() {
		busy = false;
	}
};