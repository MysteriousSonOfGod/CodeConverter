#pragma once

class VersionCheckerParent
{
public:
	virtual void Check() = 0;
	virtual ~VersionCheckerParent() = default;

protected:
	int major_;
};

class MinorCheckerParent
{
protected:
	int minor_;
};

// The Diomond of Death!
class MajorChecker : public virtual VersionCheckerParent
{
protected:
	bool CheckMajor();
private:
	float ver_half_a_;
	float ver_half_b_;
};

class MinorChecker : public virtual VersionCheckerParent, public MinorCheckerParent
{
protected:
	bool CheckMinor();
private:
	float ver_half_a_;
	float ver_half_b_;
};

class VersionChecker : public MajorChecker, public MinorChecker
{
public:
	VersionChecker(int major, int minor);
	void Check();
private:
	bool some_useless_bool_;
};

void ftGetVersion(int& major, int& minor, int& rev, int& build);