//
// Created by wojciechsalapatek on 20.05.18.
//

#include "Scheduler.h"

namespace academia {
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) : course_id_(
            course_id), teacher_id_(teacher_id), room_id_(room_id), time_slot_(time_slot), year_(year) {}

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }


    Schedule::Schedule() {}

    Schedule::Schedule(const vector<SchedulingItem> &elements) : items_(elements){}

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        items_.emplace_back(item);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        vector<SchedulingItem> teacherItems;
        std::copy_if(items_.begin(), items_.end(), back_inserter(teacherItems),
                     [teacher_id](const SchedulingItem &current){ return (current.TeacherId()  == teacher_id);});
        return Schedule(teacherItems);
    }

    Schedule Schedule::OfRoom(int room_id) const {
        vector<SchedulingItem> roomItems;
        std::copy_if(items_.begin(), items_.end(), back_inserter(roomItems),
                     [room_id](const SchedulingItem &current){ return (current.RoomId()  == room_id);});
        return Schedule(roomItems);
    }

    Schedule Schedule::OfYear(int year) const {
        vector<SchedulingItem> yearItems;
        std::copy_if(items_.begin(), items_.end(), back_inserter(yearItems),
                     [year](const SchedulingItem &current){ return (current.Year()  == year);});
        return Schedule(yearItems);
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        vector<int> all(20);
        std::iota(all.begin(), all.end(), 1);
        vector<int> result;
        std::copy_if(all.begin(), all.end(), back_inserter(result),
                     [n_time_slots, this](int current){ return !(isReserved(current) || current > n_time_slots);});
        return result;
    }

    bool Schedule::isReserved(int time_slot) const {
        for (const SchedulingItem &item : items_) if(item.TimeSlot() == time_slot) return true;
        return false;
    }

    size_t Schedule::Size() const {
        return items_.size();
    }

    SchedulingItem  Schedule::operator[](int id) const{
        for(const SchedulingItem &item : items_) return items_[id];
    }


    NoViableSolutionFound::NoViableSolutionFound() : std::runtime_error("Cannot construct schedule"){}

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule result;
        for(const auto &teacher : teacher_courses_assignment){
            for(auto i : teacher.second){
                bool find = false;
                int year = 0;
                for (auto room : rooms) {
                    for (int time = 1; time <= n_time_slots; ++time) {
                        year = FindYear(courses_of_year, i, result, time);
                        if (year != -1 && isRoomAvailable(room, time, result) && isHeAvailable(teacher.first, time, result)) {
                            result.InsertScheduleItem(SchedulingItem(i, teacher.first, room, time, year));
                            find = true;
                            break;
                        }
                    }
                    if(find) break;
                }
                if(!find) throw NoViableSolutionFound();

            }
        }
        return result;
    }


    int GreedyScheduler::FindYear(const std::map<int, std::set<int>> &courses_of_year, int course, const Schedule &schedule, int time) {
        for(auto i : courses_of_year){
            for(auto j : i.second) {
                if (j==course){
                    vector<int> avTimes = schedule.OfYear(i.first).AvailableTimeSlots(time + 1);
                    for(int k=0; k<avTimes.size();k++) if(avTimes[k]==time) return i.first;
                }
            }

        }
        return -1;
    }

    bool GreedyScheduler::isHeAvailable(int teacher, int time, const Schedule &schedule) {
        vector<int> avTimes = schedule.OfTeacher(teacher).AvailableTimeSlots(time + 1);
        return (std::find(avTimes.begin(), avTimes.end(), time) != avTimes.end());
    }

    bool GreedyScheduler::isRoomAvailable(int room, int time, const Schedule &schedule) {
        vector<int> avTimes = schedule.OfRoom(room).AvailableTimeSlots(time + 1);
        return (std::find(avTimes.begin(), avTimes.end(), time) != avTimes.end());
    }
}