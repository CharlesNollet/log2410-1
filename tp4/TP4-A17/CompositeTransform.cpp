///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"

std::vector<std::shared_ptr<AbsTransform>> AbsTransform::m_empty_transforms;


// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
	CompositeTransform* newClone = new CompositeTransform;

	newClone->m_transforms = this->m_transforms;

	return newClone;
}

// Executer les commandes enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for (auto i : m_transforms)
		i->transform(c, outFile);
}
