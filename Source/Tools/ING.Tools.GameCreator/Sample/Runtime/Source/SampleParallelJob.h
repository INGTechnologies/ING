#pragma once

/**
 *	Include Job
 */
#include <ING/Job/Job.h>
#include <ING/Job/ParallelJob.h>
#include <ING/Job/Thread/Thread.h>



/**
 *	Sample Job Struct
 */
struct SampleParallelJob : public ING::ParallelJob<SampleParallelJob> {

	SampleParallelJob(unsigned int threadCount) : ParallelJob(threadCount) {}

	void Execute(unsigned int index);

};


void SampleParallelJob::Execute(unsigned int index) {

	unsigned int s = 0;
	for (unsigned int i = 0; i < 10000000; ++i) {

		s += i;

	}

}