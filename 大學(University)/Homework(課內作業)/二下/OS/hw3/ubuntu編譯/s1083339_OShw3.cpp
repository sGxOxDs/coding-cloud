
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unistd.h>
using namespace std;

const int seed = 10;
void output(string, string);
void output(string, string, string);
int clk, slot_max;
void wait(int millisecond) {
	usleep(millisecond); //<unistd.h> convert to millisecond
	//Sleep(millisecond); // windows
}

class Moniter
{
public:
	Moniter()
	{
		pthread_mutex_init(&mutex, NULL);
		pthread_cond_init(&cond, NULL);
	};

	void acquire()
	{
		if (pthread_mutex_lock(&mutex) != 0)
			pthread_cond_wait(&cond, &mutex);
	};

	void release()
	{
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	};

	~Moniter()
	{
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&cond);
	};
private:

	pthread_mutex_t mutex;
	pthread_cond_t cond;
}replace_pork, output_lock, clk_lock;

/*Moniter store_permit, slot_permit, freezer_permit;

void get_two_permit(Moniter& a, Moniter& b)
{
	a.acquire();
	b.acquire();
};
void release_two_permit(Moniter& a, Moniter& b)
{
	a.release();
	b.release();
};*/

int pork_max = 0;
struct Pork
{
	int id;
	//�ɶ���� ms �˼ƭp��
	int break_max;
	//�ɶ���� ms �˼ƭp��
	int freezer_max;
	//�ɶ���� ms
	int freezer_proess;

	// 0=��� 1=�Q���� 2=��l 3=�a��
	int stage;
};
queue<Pork> store;
queue<Pork> slot;
vector<Pork> freezer;

int cutter_max = 0;
int packer_max = 0;
struct My_Data
{
	//Moniter factory_permit;
	int id;
	pthread_t t;
	bool trywait = false;
	bool pthread_active = false;
	bool active;
	bool keep = false;
	bool have_pork;
	// �B�z�ަת��L�{
	int process;
	Pork pork_deal_with;
	int wait_process;
	// 0=cutter 1=packer
	int factory_type;
	// 0=�u�@ 1=���@ 2=�˰Q
	int stage;
};
vector<My_Data> cutters;
vector<My_Data> packers;

bool any_factory_work()
{
	for (int i = 0; i < cutters.size(); i++)
		if (cutters[i].active)
			return true;
	for (int i = 0; i < packers.size(); i++)
		if (packers[i].active)
			return true;
	return false;
}
void* cutter(void*);
void* packer(void*);

void* cutter(void* data) {
	My_Data* my_data = (My_Data*)data; // ���o��J���
	my_data->pthread_active = true;
	srand(seed);
	while (true)
	{
		clk_lock.acquire();
		// work mode
		if (my_data->have_pork)
		{
			if (my_data->process == 0 && !my_data->active)
			{
				my_data->active = true;
				my_data->process = rand() % 21 * 10 + 100;
				output("CUTTER#" + to_string(my_data->id), "��k1 cutting... cutting... Pork#"+ to_string(my_data->pork_deal_with.id), to_string(my_data->process));
			}
			if (my_data->process == 0)
			{
				replace_pork.acquire();
				//�����X�h
				if (my_data->process == 0)
				{
					my_data->pork_deal_with.stage = 1;
					if (!my_data->keep)
						output("Pork#" + to_string(my_data->pork_deal_with.id), "leaves CUTTER#" + to_string(my_data->id) + " (complete 1st stage)");

					if (my_data->have_pork && slot.size() < slot_max)
					{
						slot.push(my_data->pork_deal_with);
						my_data->have_pork = false;
						my_data->keep = false;
						output("Pork#" + to_string(my_data->pork_deal_with.id), "waiting in the slot (cutted)");
					}
					for (int i = 0; i < packers.size(); i++)
					{
						if (!packers[i].have_pork && my_data->have_pork)
						{
							packers[i].pork_deal_with = my_data->pork_deal_with;
							packers[i].have_pork = true;
							my_data->have_pork = false;
							my_data->keep = false;
							output("Pork#" + to_string(my_data->pork_deal_with.id), ": enters to the factory (PACKER#"+to_string(packers[i].id)+")");
							pthread_create(&packers[i].t, NULL, packer, (void*)&packers[i]);
						}
					}
					
					if (my_data->have_pork)
					{
						my_data->keep = true;
					}
				}
				//��������U�@��
				if (my_data->process == 0 && !my_data->have_pork)
				{
					for (int i = 0; i < slot.size(); i++)
					{
						auto temp = slot.front();
						slot.pop();

						if (!my_data->have_pork && temp.stage == 0)
						{
							my_data->pork_deal_with = temp;
							my_data->have_pork = true;
							i--;
						}
						else
						{
							slot.push(temp);
						}
					}
				}
				
				replace_pork.release();
				if (my_data->process == 0 && !my_data->keep && my_data->have_pork)
				{
					my_data->process = rand() % 21 * 10 + 100;
					output("CUTTER#" + to_string(my_data->id), "��k2 cutting... cutting... Pork#" + to_string(my_data->pork_deal_with.id), to_string(my_data->process));
				}
				else if(!my_data->keep)
				{
					my_data->active = false;
				}
			}
		}
		// �˰Q mode
		else if (!any_factory_work())
		{
			if (!my_data->trywait)
			{
				my_data->wait_process = rand() % 10 * 10 + 10;
				my_data->trywait = true;
			}
			else if (my_data->wait_process <= 0 && my_data->trywait)
			{
				my_data->trywait = false;
				output("CUTTER#" + to_string(my_data->id), "under reviewing together...");
				clk_lock.release();
				break;
			}
		}
		// ���@ mode
		else
		{
			output("CUTTER#" + to_string(my_data->id), "under maintenance.");
			clk_lock.release();
			break;
		}
		clk_lock.release();
		//wait(10);
	}
	my_data->pthread_active = false;
	pthread_exit(NULL); // ���}�l�����
	return NULL;
}

void* packer(void* data) {
	My_Data* my_data = (My_Data*)data; // ���o��J���
	my_data->pthread_active = true;
	srand(seed);
	while (true)
	{
		clk_lock.acquire();
		// work mode
		if (my_data->have_pork)
		{
			if (my_data->process <= 0 && !my_data->active)
			{
				my_data->active = true;
				my_data->process = rand() % 51 * 10 + 500;
				output("PACKER#" + to_string(my_data->id), "��k1 processing & Packing the Pork#" + to_string(my_data->pork_deal_with.id), to_string(my_data->process));
			}
			if (my_data->process <= 0)
			{
				replace_pork.acquire();
				//��l�X�h
				if (my_data->process <= 0)
				{
					my_data->pork_deal_with.stage = 2;

					if (my_data->have_pork)
					{
						output("Pork#" + to_string(my_data->pork_deal_with.id), "leaves PACKER#" + to_string(my_data->id) + " (Complete)");
						my_data->have_pork = false;
					}
				}
				//��������U�@��
				if (my_data->process <= 0 && !my_data->have_pork)
				{
					for (int i = 0; i < slot.size(); i++)
					{
						auto temp = slot.front();
						slot.pop();

						if (!my_data->have_pork && temp.stage == 1)
						{
							my_data->pork_deal_with = temp;
							my_data->have_pork = true;
							i--;
						}
						else
						{
							slot.push(temp);
						}
					}
				}
				replace_pork.release();
				if (my_data->process <= 0 && my_data->have_pork)
				{
					my_data->process = rand() % 51 * 10 + 500;
					output("PACKER#" + to_string(my_data->id), "��k2 processing & Packing the Pork#" + to_string(my_data->pork_deal_with.id), to_string(my_data->process));
				}
				else
				{
					my_data->active = false;
				}
			}
		}
		// �˰Q mode
		else if (!any_factory_work())
		{
			if (!my_data->trywait)
			{
				my_data->wait_process = rand() % 10 * 10 + 10;
				my_data->trywait = true;
			}
			else if (my_data->wait_process <= 0 && my_data->trywait)
			{
				my_data->trywait = false;
				output("PACKER#" + to_string(my_data->id), "under reviewing together...");
				clk_lock.release();
				break;
			}
		}
		// ���@ mode
		else
		{
			output("PACKER#" + to_string(my_data->id), "under maintenance.");
			clk_lock.release();
			break;
		}
		clk_lock.release();
		//wait(10);
	}
	my_data->pthread_active = false;
	pthread_exit(NULL); // ���}�l�����
	return NULL;
}

bool all_pork_done()
{
	if (!store.empty())
		return false;
	if (!slot.empty())
		return false;
	if (!freezer.empty())
		return false;

	for (int i = 0; i < cutter_max; i++)
		if (cutters[i].active)
			return false;
	for (int i = 0; i < packer_max; i++)
		if (packers[i].active)
			return false;

	return true;
}

bool freezer_timeup()
{
	for (int i = 0; i < freezer.size(); i++)
		if (freezer[i].freezer_proess == 0)
			return true;
	return false;
}

bool pork_break()
{
	replace_pork.acquire();
	for (int i = 0; i < slot.size(); i++)
	{
		auto temp = slot.front();
		slot.pop();
		slot.push(temp);

		if (temp.break_max <= 0)
		{
			replace_pork.release();
			return true;
		}
	}
	replace_pork.release();
	return false;
}

void output(string first, string second)
{
	//clk_lock.acquire();
	output_lock.acquire();
	cout << clk << "ms -- " << first << ": " << second << endl;
	output_lock.release();
	//clk_lock.release();
}
void output(string first, string second,string third)
{
	//clk_lock.acquire();
	output_lock.acquire();
	cout << clk << "ms -- " << first << ": " << second << " -- " << third << "ms" << endl;
	output_lock.release();
	//clk_lock.release();
}

int main(int argc, char* argv[])
{
	int porks, cutter_num, packer_num;
	porks = 15;
	slot_max = 5;
	cutter_num = 1;
	packer_num = 1;
	// �ɤJ���O�Ѽ�
	if (argc >= 3)
	{
		porks = atoi(argv[1]);
		slot_max = atoi(argv[2]);
	}
	if (argc >= 5)
	{
		cutter_num = atoi(argv[3]);
		packer_num = atoi(argv[4]);
	}
	
	// init
	srand(seed);
	for (int i = 0; i < porks; i++)
	{
		Pork temp_pork;
		temp_pork.id = ++pork_max;
		temp_pork.stage = 0;
		temp_pork.break_max = (rand() % 5) * 200 + 2000;
		temp_pork.freezer_proess = 0;
		temp_pork.freezer_max = 5 * 1000;
		store.push(temp_pork);
	}
	for (int i = 0; i < cutter_num; i++)
	{
		My_Data temp_data;
		temp_data.id = ++cutter_max;
		temp_data.factory_type = 0;
		temp_data.stage = 1;
		temp_data.active = false;
		temp_data.have_pork = false;
		temp_data.process = 0;
		temp_data.wait_process = 0;
		cutters.push_back(temp_data);
	}
	for (int i = 0; i < packer_num; i++)
	{
		My_Data temp_data;
		temp_data.id = ++packer_max;
		temp_data.factory_type = 1;
		temp_data.stage = 1;
		temp_data.active = false;
		temp_data.have_pork = false;
		temp_data.process = 0;
		temp_data.wait_process = 0;
		packers.push_back(temp_data);
	}
	clk = 0;

	for (int i = 0; i < cutter_max; i++)
		pthread_create(&cutters[i].t, NULL, cutter, (void*)&cutters[i]);
	for (int i = 0; i < packer_max; i++)
		pthread_create(&packers[i].t, NULL, packer, (void*)&packers[i]);

	int store_cd = (rand() % 6 * 10) + 50;
	while (true)
	{
		// store to slot or freezer
		if (!store.empty() && store_cd == 0)
		{
			int freezer_time = (rand() % 21 * 10) + 300;
			replace_pork.acquire();
			auto temp = store.front();
			store.pop();
			if (slot.size() < slot_max)
			{
				slot.push(temp);
				output("Pork#" + to_string(temp.id), "waiting in the slot");
			}
			else
			{
				temp.freezer_proess += freezer_time;
				temp.freezer_max -= freezer_time;
				freezer.push_back(temp);
				output("Pork#" + to_string(temp.id), "has been sent to the Freezer", to_string(freezer_time));
			}
			replace_pork.release();

			store_cd = (rand() % 6 * 10) + 50;
		}

		// freezer to freezer or slot
		if (!freezer.empty() && freezer_timeup())
		{
			replace_pork.acquire();
			while (freezer_timeup())
			{
				for (int i = 0; i < freezer.size(); i++)
					if (freezer[i].freezer_proess == 0)
					{
						auto temp = freezer[i];
						freezer.erase(freezer.begin() + i);
						if (slot.size() < slot_max)
						{
							slot.push(temp);
							output("Pork#" + to_string(temp.id), "waiting in the slot");
						}
						else if (temp.freezer_max <= 0)
						{
							slot.push(temp);
							output("Pork#" + to_string(temp.id), "waiting in the slot(freezer time up)");
						}
						else
						{
							int freezer_time = (rand() % 21 * 10) + 300;
							temp.freezer_proess += freezer_time;
							temp.freezer_max -= freezer_time;
							freezer.push_back(temp);
							output("Pork#" + to_string(temp.id), "has been sent to the Freezer", to_string(freezer_time));
						}
						break;
					}
			}
			replace_pork.release();
		}

		// check slot pork break or not
		if (!slot.empty() && pork_break())
		{
			while (pork_break())
			{
				replace_pork.acquire();
				for (int i = 0; i < slot.size(); i++)
				{
					auto temp = slot.front();
					slot.pop();

					if (temp.break_max > 0)
						slot.push(temp);
					else
					{
						temp.stage = 3;
						output("Pork#" + to_string(temp.id), "spoiled(�a��)");
					}
				}
				replace_pork.release();
			}
		}


		// slot to cutter or packer
		if (!slot.empty())
		{
			replace_pork.acquire();
			for (int i = 0; i < cutters.size(); i++)
			{
				for (int j = 0; j < slot.size(); j++)
				{
					auto temp = slot.front();
					slot.pop();

					if (!cutters[i].have_pork && temp.stage == 0)
					{
						cutters[i].pork_deal_with = temp;
						cutters[i].have_pork = true;
						output("Pork#" + to_string(temp.id), "enters the CUTTER#"+to_string(cutters[i].id));
						pthread_create(&cutters[i].t, NULL, cutter, (void*)&cutters[i]);
						j--;
					}
					else
					{
						slot.push(temp);
					}
				}
			}
			for (int i = 0; i < packers.size(); i++)
			{
				for (int j = 0; j < slot.size(); j++)
				{
					auto temp = slot.front();
					slot.pop();

					if (!packers[i].have_pork && temp.stage == 1)
					{
						packers[i].pork_deal_with = temp;
						packers[i].have_pork = true;
						output("Pork#" + to_string(temp.id), "enters the PACKER#" + to_string(packers[i].id));
						pthread_create(&packers[i].t, NULL, packer, (void*)&packers[i]);
						j--;
					}
					else
					{
						slot.push(temp);
					}
				}
			}
			replace_pork.release();
		}
		

		// end check
		replace_pork.acquire();
		if (all_pork_done()) break;
		replace_pork.release();

		// time pass
		clk_lock.acquire();
		store_cd -= 10;
		for (int i = 0; i < freezer.size(); i++)
			freezer[i].freezer_proess -= 10;
		replace_pork.acquire();
		for (int i = 0; i < slot.size(); i++)
		{
			auto temp = slot.front();
			slot.pop();
			temp.break_max -= 10;
			slot.push(temp);
		}
		replace_pork.release();
		for (int i = 0; i < cutters.size(); i++)
		{
			if (cutters[i].trywait)
				cutters[i].wait_process -= 10;
			if (cutters[i].process > 0)
				cutters[i].process -= 10;
		}
		for (int i = 0; i < packers.size(); i++)
		{
			if (packers[i].trywait)
				packers[i].wait_process -= 10;
			if (packers[i].process > 0)
				packers[i].process -= 10;
		}
		clk_lock.release();

		wait(5);

		clk_lock.acquire();
		clk += 10;
		clk_lock.release();
	}

	for (int i = 0; i < cutters.size(); i++)
		while (cutters[i].pthread_active) 
		{
			if (cutters[i].trywait)
				cutters[i].wait_process -= 10;
			if (cutters[i].process > 0)
				cutters[i].process -= 10;
		}
	for (int i = 0; i < packers.size(); i++)
		while (packers[i].pthread_active)
		{
			if (packers[i].trywait)
				packers[i].wait_process -= 10;
			if (packers[i].process > 0)
				packers[i].process -= 10;
		}
	return 0;
}
