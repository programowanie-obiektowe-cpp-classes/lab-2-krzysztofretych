#pragma once
#include<iostream>
#include "Resource.hpp"
using namespace std;
class ResourceManager
{
public:
    ResourceManager()
    {
        res=new Resource;
    }
    ~ResourceManager()
    {
        delete res;
    }
    ResourceManager(const ResourceManager& kopia)
    {
        res=new Resource(*kopia.res);
    }
    ResourceManager& operator=(const ResourceManager& xxx)
    {
        if (&xxx!=this)
        {
            delete res;
            res=new Resource{*xxx.res};
        }
        return *this;
    }
    ResourceManager(ResourceManager&& yyy)
    {
        res=yyy.res;
        yyy.res=nullptr;
    }
    ResourceManager& operator=(ResourceManager&& zzz)
    {
        delete res;
        res=zzz.res;
        zzz.res=nullptr;
        return *this;
    }
    double get()
    {
        return res->get();
    }
private:
    Resource* res=nullptr;
};
