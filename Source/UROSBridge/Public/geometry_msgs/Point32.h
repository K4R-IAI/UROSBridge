#pragma once

#include "ROSBridgeMsg.h"


namespace geometry_msgs
{
	class Point32 : public FROSBridgeMsg
	{
		float X;
		float Y;
		float Z;
	public:
		Point32()
		{
			MsgType = "geometry_msgs/Point32";
		}

		Point32
		(
			float InX,
			float InY,
			float InZ
		):
			X(InX),
			Y(InY),
			Z(InZ)
		{
			MsgType = "geometry_msgs/Point32";
		}

		~Point32() override {}

		float GetX() const
		{
			return X;
		}

		float GetY() const
		{
			return Y;
		}

		float GetZ() const
		{
			return Z;
		}

		void SetX(float InX)
		{
			X = InX;
		}

		void SetY(float InY)
		{
			Y = InY;
		}

		void SetZ(float InZ)
		{
			Z = InZ;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			X = JsonObject->GetNumberField(TEXT("x"));

			Y = JsonObject->GetNumberField(TEXT("y"));

			Z = JsonObject->GetNumberField(TEXT("z"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			X = BsonObject->GetNumberField(TEXT("x"));

			Y = BsonObject->GetNumberField(TEXT("y"));

			Z = BsonObject->GetNumberField(TEXT("z"));

		}

		static Point32 GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Point32 Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static Point32 GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			Point32 Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetNumberField(TEXT("x"), X);
			Object->SetNumberField(TEXT("y"), Y);
			Object->SetNumberField(TEXT("z"), Z);
			return Object;
		}
		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetNumberField(TEXT("x"), X);
			Object->SetNumberField(TEXT("y"), Y);
			Object->SetNumberField(TEXT("z"), Z);
			return Object;
		}
		virtual FString ToYamlString() const override
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
	};
}