//
// Created by wojciechsalapatek on 08.05.18.
//

#include "Serialization.h"

academia::Serializer::Serializer(std::ostream *out) : out_(out){}

std::ostream* academia::Serializer::GetOut() {
    return out_;
}

academia::Room::Room(int buldingNr, std::string numer, academia::Room::Type type) : bulding_(buldingNr), number_(numer), type_(type){}

void academia::Room::Serialize(academia::Serializer *serializer) const{
    serializer->Header("room");
    serializer->IntegerField("id", bulding_);
    serializer->StringField("name", number_);
    serializer->StringField("type", TypeToString(type_));
    serializer->Footer("room");
}

std::string academia::Room::TypeToString(academia::Room::Type type) const{
    switch(type) {
        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
}

academia::Building::Building(int id, const string &name, const vector<academia::Room> &rooms) : id_(id), name_(name), rooms_(rooms){}

void academia::Building::Serialize(academia::Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    std::vector<std::reference_wrapper<const Serializable>> rooms;
    for (auto &i : rooms_) rooms.emplace_back(std::cref(i));
    serializer->ArrayField("rooms", rooms);
    serializer->Footer("building");
}

int academia::Building::Id() const{
    return id_;
}


academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out), isFirst_(true){}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": "<<std::to_string(value);
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    string val = std::to_string(value);
    val.erase ( val.find_last_not_of('0') + 1, std::string::npos );
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": "<<val;
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": "<<"\""<<value<<"\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    string val;
    value ? val = "true" : val = "false";
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": "<<val;
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": ";
    value.Serialize(this);
}

void academia::JsonSerializer::Header(const std::string &object_name) {
    isFirst_ = true;
    *GetOut()<<"{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *GetOut()<<"}";
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    if(!isFirst_) *GetOut()<<", ";
    isFirst_ = false;
    *GetOut()<<"\""<<field_name<<"\""<<": [";
    for(int i=0; i<value.size();++i) {
        value[i].get().Serialize(this);
        if(i != value.size()-1)*GetOut()<<", ";
    }
    *GetOut()<<"]";
}


academia::XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    *GetOut()<<"<"<<field_name<<">"<<std::to_string(value)<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    string val = std::to_string(value);
    val.erase ( val.find_last_not_of('0') + 1, std::string::npos );
    *GetOut()<<"<"<<field_name<<">"<<val<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *GetOut()<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    string val;
    value ? val = "true" : val = "false";
    *GetOut()<<"<"<<field_name<<">"<<val<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    *GetOut()<<"<"<<field_name<<">";
    value.Serialize(this);
    *GetOut()<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *GetOut()<<"<"<<field_name<<">";
    for(const Serializable &i : value) i.Serialize(this);
    *GetOut()<<"<\\"<<field_name<<">";
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    *GetOut()<<"<"<<object_name<<">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    *GetOut()<<"<\\"<<object_name<<">";
}

academia::BuildingRepository::BuildingRepository() : buildings_(){}

academia::BuildingRepository::BuildingRepository(std::initializer_list<Building> buildings) : buildings_(buildings){}

void academia::BuildingRepository::Add(academia::Building building) {
    buildings_.emplace_back(building);
}

void academia::BuildingRepository::StoreAll(academia::Serializer *serializer) const {
    std::vector<std::reference_wrapper<const Serializable>> buildings;
    for (auto &i : buildings_) buildings.emplace_back(std::cref(i));
    serializer->Header("building_repository");
    serializer->ArrayField("buildings", buildings);
    serializer->Footer("building_repository");
}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int id) const{
    for (const Building &b : buildings_) if(b.Id() == id) return b;
}
