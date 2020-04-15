#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : hp(hp), type(type) { }

Enemy::Enemy(Enemy &obj){
	*this = obj;
}

Enemy::~Enemy() { }

Enemy &Enemy::operator=(Enemy const &r) {
	this->hp = r.hp;
	this->type = r.type;
	return (*this);
}

std::string Enemy::getType() const {
	return (this->type);
}

int Enemy::getHP() const {
	return (this->hp);
}

void Enemy::takeDamage(int amount) {
	if (amount < 0)
		return;
	else if (amount < this->hp )
		this->hp -= amount;
	else
		this->hp = 0;
}

void Enemy::setHP(int i) {
	this->hp = i;
}