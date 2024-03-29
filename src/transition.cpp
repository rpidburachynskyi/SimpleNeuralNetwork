#include "transition.h"
#include "neuron.h"
#include <iostream>

Transition::Transition(Neuron *from,
					   Neuron *to,
					   const double &value)
{
	m_from = from;
	m_to = to;
	m_value = value;

	m_from->forwardTransitions().push_back(this);
	m_to->backTransitions().push_back(this);
}

Transition::~Transition()
{
	if(m_from != nullptr)
	{
		delete m_from;
		m_from = nullptr;
	}
}

Neuron *Transition::from() const
{
	return m_from;
}

Neuron *Transition::to() const
{
	return m_to;
}

double Transition::value() const
{
	return m_value;
}
