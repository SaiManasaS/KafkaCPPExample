#pragma once 

#include <iostream>
#include "kafkaConsumer.h"
#include "librdkafka/rdkafkacpp.h"

using namespace std;

void main()
{
	int32_t partition = RdKafka::Topic::PARTITION_UA;
	int64_t start_offset = RdKafka::Topic::OFFSET_BEGINNING;

	/*
     * Create configuration objects
     */
	RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
	RdKafka::Conf* tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

	cout << "conf: " << conf << endl;
	cout << "tconf: " << tconf << endl;

	RdKafka::Conf::ConfResult confRes;
	std::string features;
	std::string errstr, optarg;
	string brokers = "localhost:9092";

	/*
     * Set configuration properties
     */

	if (conf)
	{
		conf->set("client.id", "MyClient", errstr);
		//conf->set("client.id", "MyClient", errstr);
		conf->set("group.id", "MyGroup", errstr);
		
		conf->set("bootstrap.servers", brokers, errstr);
	}

	/*
	if (!debug.empty()) 
	{
		if (conf->set("debug", debug, errstr) != RdKafka::Conf::CONF_OK) 
		{
			std::cerr << errstr << std::endl;
			exit(1);
		}
	}

	if (conf->set("compression.codec", "gzip", errstr) != RdKafka::Conf::CONF_OK) 
	{
		std::cerr << errstr << std::endl;
		//exit(1);
	}
	*/

	/*
     * Create consumer using accumulated global configuration.
     */

	cout << "Creating a consumer" << endl;

	RdKafka::Consumer* consumer = RdKafka::Consumer::create(conf, errstr);

	cout << "Checking for a consumer" << endl;
	if (!consumer) 
	{
		std::cerr << "Failed to create consumer: " << errstr << std::endl;
		exit(1);
	}

	//confRes = conf->get("builtin.features", features);
	confRes = conf->get("compression.codec", features);

	cout << "confRes: " << confRes << endl;
	cout << "features: " << features.c_str() << endl;

	cout << "features: " << features.c_str() << endl;

//	conf->set(

	while (1);
}
