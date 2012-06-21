// Standard headers
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <iostream> 
#include <sstream>
// Flite headers
#include <flite.h>
#include "edu_cmu_us_speech_tts_wordcallback.hh"
namespace FliteEngine{

Utterance::Utterance(String id, String text)
{
  id_ = id;
  text_ = text;
}

Utterance::~Utterance() {}

String Utterance::getText()
{
  return text_;
}

String Utterance::getID()
{
  return id_;
}

int UttEventCallback::sendEvent(String utt_id, String event_type, int charIndex, float dur) 
{
}

Flite::Flite()
{
  utt_ = NULL;
  utt_event_callback_ = NULL;
  seg_callbacks_ = false;
}


void Flite::setSegmentCallbacks(bool scb)
{
  seg_callbacks_ = scb;
}

void Flite::setUttEventCallback(UttEventCallback* cb) 
{
  utt_event_callback_ = cb;
}
Flite::~Flite(){}
}
/*end*/
