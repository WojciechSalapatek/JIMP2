//
// Created by wojciechsalapatek on 20.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <experimental/optional>


using std::vector;

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule{
    public:
        Schedule();
        explicit Schedule(const vector<SchedulingItem> &elements);
        void InsertScheduleItem(const SchedulingItem &item);
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        size_t Size() const;
        SchedulingItem operator[](int id) const;
    private:
        bool isReserved(int time_slot) const;
        vector<SchedulingItem> items_;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>>
        &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound();
    };

    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>>
        &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override ;

    private:
        int FindYear(const std::map<int, std::set<int>> &courses_of_year, int course, const Schedule &schedule, int time);
        bool isHeAvailable(int teacher, int time, const Schedule &schedule);
        bool isRoomAvailable(int room, int time, const Schedule &schedule);
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
