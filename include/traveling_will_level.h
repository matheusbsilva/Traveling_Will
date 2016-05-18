#ifndef TRAVELING_WILL_LEVEL_H
#define TRAVELING_WILL_LEVEL_H

#include <string>
#include <memory>
#include <ijengine/level.h>
#include <ijengine/texture.h>
#include <ijengine/events_translator.h>

using std::string;
using std::shared_ptr;

using namespace ijengine;

class TravelingWillLevel : public Level, public GameEventsListener {
public:
    TravelingWillLevel(int r, int g, int b, const string& next_level = "");
    ~TravelingWillLevel();

    bool done() const;
    string next() const;

    bool on_event(const GameEvent& event);

protected:
    void update_self(unsigned now, unsigned last);
    void draw_self(Canvas *canvas, unsigned now, unsigned last);

private:
    typedef enum { RUNNING, JUMPING, SLIDING } State;
    int m_r, m_g, m_b;
    bool m_done;
    string m_next;
    int m_start;
    double m_camera_x, m_camera_y;
    double m_will_x, m_will_y;
    double m_x_speed, m_y_speed;
    State m_state;
    shared_ptr<Texture> m_texture, m_will;
    EventsTranslator m_translator;
};

#endif