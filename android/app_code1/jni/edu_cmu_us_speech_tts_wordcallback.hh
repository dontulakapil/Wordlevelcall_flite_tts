#include "edu_cmu_cs_speech_tts_String.hh"
#include <string>
#include <vector>
#include <iostream> 
#include <sstream>
#define STREAM_STATUS_ERR(X, Y)			\
  Y = X; \
  if(0 != Y) { return CST_AUDIO_STREAM_STOP;} \

#define START_EVENT "start"
#define WORD_EVENT "word"
#define END_EVENT "end"
#define SEGMENT_EVENT "segment"
using namespace std;
namespace FliteEngine {
class Utterance
{
public:
  Utterance(String id,String text);
  String getText();
  String getID();
  virtual ~Utterance();
  vector<float> word_durations;
  vector<int> word_indices;
  vector<float> seg_durations;
  vector<String> seg_labels;
  int cur_index;
  int cur_seg_index;

private:
  String id_;
  String text_;
};

class UttEventCallback
{
public:
  virtual int sendEvent(String utt_id, String event_type, int charIndex, float dur);
  virtual ~UttEventCallback() {};
};

class Flite
{
public:
  Flite();
  virtual ~Flite();
  static int callbackHandler(const cst_wave *w, int start, int size, int last, cst_audio_streaming_info_struct *asi);
  void synthesize(String utt_id, String utt_text);

  void setUttEventCallback(UttEventCallback* cb);
  void setSegmentCallbacks(bool scb);

  cst_voice* voice_;
  Utterance* utt_;
  cst_audiodev *ad_;
  UttEventCallback* utt_event_callback_;
  bool seg_callbacks_;
};
}
