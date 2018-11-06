%module(directors="1", allprotected="1") AlgoSE

%include <std_string.i>
%include <cstring.i>

%{
#include "Defines.h"
#include "IEngine.h"
#include "Engine.h"
#include "Service.h"
#include "Date.h"
#include "DateTime.h"
#include "circular.h"
#include "Event.h"
#include "DataSeries.h"
#include "BarSeries.h"
#include "Cross.h"
#include "Technical.h"
#include "HighLow.h"
#include "MA.h"
#include "AlgoOrder.h"
#include "OrderList.h"
#include "PositionList.h"
#include "Strategy.h"

using namespace AlgoSE;

%}

%feature ("flatnested");

%feature("director") AlgoSE::IEngine::Listener;
%thread AlgoSE::IEngine::Listener;

%feature("director") AlgoSE::Strategy;
%thread AlgoSE::Strategy;

%extend AlgoSE::BarSeries { 
	SequenceDataSeries<double>& getOpenDataSeries() { 
        return (SequenceDataSeries<double>&)$self->getOpenDataSeries();
    }
    SequenceDataSeries<double>& getCloseDataSeries() { 
        return (SequenceDataSeries<double>&)$self->getCloseDataSeries();
    } 
    SequenceDataSeries<double>& getHighDataSeries() { 
        return (SequenceDataSeries<double>&)$self->getHighDataSeries();
    } 
    SequenceDataSeries<double>& getLowDataSeries() { 
        return (SequenceDataSeries<double>&)$self->getLowDataSeries();
    }
    SequenceDataSeries<long long>& getVolumeDataSeries() { 
        return (SequenceDataSeries<long long>&)$self->getVolumeDataSeries();
    }
    SequenceDataSeries<long long>& getOpenIntDataSeries() { 
        return (SequenceDataSeries<long long>&)$self->getOpenIntDataSeries();
    }
}

%ignore AlgoSE::BarSeries::getOpenDataSeries(); 
%ignore AlgoSE::BarSeries::getCloseDataSeries(); 
%ignore AlgoSE::BarSeries::getHighDataSeries(); 
%ignore AlgoSE::BarSeries::getLowDataSeries(); 
%ignore AlgoSE::BarSeries::getVolumeDataSeries(); 
%ignore AlgoSE::BarSeries::getOpenIntDataSeries(); 

%include "Defines.h"
%include "Date.h"

%rename(DateTimeToString) operator std::string;
%include "DateTime.h"

%extend AlgoSE::DateTime {
  std::string __str__() {
    return self->toString();
  }
}

%include "Event.h"
%include "DataSeries.h"

%template(DoubleSequenceDataSeries)    AlgoSE::SequenceDataSeries<double>;
%template(TickSequenceDataSeries)      AlgoSE::SequenceDataSeries<Tick>;
%template(BarSequenceDataSeries)       AlgoSE::SequenceDataSeries<Bar>;

%extend AlgoSE::SequenceDataSeries<double> {
    double __getitem__(unsigned int i) {
        return (*($self))[i];
    }
}

%extend AlgoSE::SequenceDataSeries<Tick> {
    AlgoSE::Tick __getitem__(unsigned int i) {
        return (*($self))[i];
    }
}

%extend AlgoSE::SequenceDataSeries<Bar> {
    AlgoSE::Bar __getitem__(unsigned int i) {
        return (*($self))[i];
    }
}

%include "BarSeries.h"
%include "Technical.h"

%cstring_bounded_output(char* clOrdId, 32); 

%typemap(argout) char* clOrdId {
    if (result) {
        $result = SWIG_FromCharPtr($1);
    } else {
        $result = Py_None;
        Py_INCREF(Py_None);
    }
}

%include "IEngine.h"
%include "Engine.h"
%include "Service.h"
#include "ServiceConfig.h"
%include "OrderList.h"
%include "PositionList.h"
%include "AlgoOrder.h"
%include "StrategyConfig.h"
%include "Strategy.h"

%template(DoubleEventWindow) AlgoSE::EventWindow< double, double >;
%template(DoubleEventBasedFilter) AlgoSE::EventBasedFilter<double, double>;

%include "MA.h"
%include "HighLow.h"
%include "Cross.h"