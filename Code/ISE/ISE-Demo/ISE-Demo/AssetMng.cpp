#include "AssetMng.h"


AssetMng::AssetMng(void)
{
}


AssetMng::~AssetMng(void)
{
}

void AssetMng::Load(AS_TYPE type,std::string location)
{
	if (type == AS_OBJ)
	{
		//if(object.find(location) == object.end())
		if(!object.count(location))
		{
			//std::cout << "Run" << std::endl;
			object[location]=objLoader::load(location);
		}
		else
		{
			//std::cout << "Object Already exists in Asset manager" << std::endl;
		}
	}
	else if(type == AS_TEXTURE)
	{
		if(!texture.count(location))
		{
			//check out this section i'm not sure if it get destroyed if i don't new
			//std::cout << "Run Texture" << std::endl;
			Texture temp ;
			temp.load(location);
			texture[location]=temp;
		}
		else
		{
			//std::cout << "Texture Already Exists" << std::endl;
		}
	}
	else
	{
		std::cout<<"Error with the type specified" << std::endl;
	}
}

void AssetMng::getData(std::string location, VAO &data)
{
	
		if (object.count(location))//if found
		{
			data = object[location];
			//return (object[location]);
		}
		else
		{
			
			err.error = "Object could not be found please try again";
			//return (err);
		}

	/*
	else if (type == AS_TEXTURE)
	{
		if
	}
	else
	{
		Error err;
		err.error = "Enum Type specified not correct";
		//return (err);
	}*/
	
}

/*
void AssetMng::getData(std::string location, Texture &text)
{
	if(texture.count(location))
	{
		text = texture[location];
	}
	else
	{
		err.error = "Error: Texture does not exist" ;
	}
}*/

void AssetMng::getData(std::string location)
{
	if(texture.count(location))
	{
		texture[location].bind();
	}
}

