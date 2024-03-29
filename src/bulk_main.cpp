// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "CmdExecutor.h"
#include "CmdStreamWorker.h"
#include "Implementer.h"
#include "CmdLogger.h"
#include <memory>

int main(int argc, char* argv[]) {
	if (argc != 2) 
		return -1;

	const size_t sequenceLength = std::stoul(argv[1]);

	auto impl = std::make_unique<Implementer>(sequenceLength);
	impl->addCmdExecutor(std::move(std::make_unique<CmdExecutor>()));
	impl->addCmdExecutor(std::move(std::make_unique<CmdLogger>()));

	CmdStreamWorker worker(std::move(impl));

	worker.run(std::cin);
}