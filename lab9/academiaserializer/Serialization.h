//
// Created by wojciechsalapatek on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>
#include <ostream>
#include <experimental/optional>

using std::vector;
using std::string;
namespace academia {

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer* serializer) const =0;
    };

    class Serializer{
    public:
        explicit Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
        std::ostream* GetOut();
    private:
        std::ostream *out_;

    };

    class Room : public Serializable{
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int buldingNr, std::string numer, Room::Type type);
        std::string TypeToString(Type type) const;
        void Serialize(Serializer* serializer) const override ;
    private:
        int bulding_;
        std::string number_;
        Room::Type type_;
    };

    class Building : public Serializable{
    public:
        Building(int id, const string &name,const vector<Room> &rooms);
        void Serialize(Serializer* serializer) const override;
        int Id() const;

    private:
        vector<Room> rooms_;
        int id_;
        string name_;

    };

    class JsonSerializer : public Serializer {
    public:
        explicit JsonSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    private:
        bool isFirst_;
    };

    class XmlSerializer : public Serializer {
    public:
        explicit XmlSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    };

    class BuildingRepository {
    public:
        BuildingRepository();
        BuildingRepository(std::initializer_list<Building> buildings);
        std::experimental::optional<Building> operator[](int id) const;
        void Add(Building building);
        void StoreAll(Serializer *serializer) const;

    private:
        vector<Building> buildings_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
