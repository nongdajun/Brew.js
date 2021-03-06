#include <bjs/Modules/NX/NX.hpp>

namespace bjs::modules::NX
{
    js::Function reboot(js::NativeContext Context)
    {
        bpcInitialize();
        bpcRebootSystem();
        bpcExit();
        return js::Return::Void;
    }

    js::Function shutDown(js::NativeContext Context)
    {
        bpcInitialize();
        bpcShutdownSystem();
        bpcExit();
        return js::Return::Void;
    }

    js::Function getTitles(js::NativeContext Context)
    {
        js::FunctionHandler handler(Context);
        if(R_SUCCEEDED(ncmInitialize()))
        {
            js::Array arr(Context);
            handler.ReturnArray(arr);
            NcmContentMetaDatabase *metadb = (NcmContentMetaDatabase*)malloc(sizeof(*metadb));
            NcmApplicationContentMetaKey *metas = (NcmApplicationContentMetaKey*)malloc(sizeof(NcmApplicationContentMetaKey) * 32);
            u32 total = 0;
            u32 written = 0;
            ncmOpenContentMetaDatabase(FsStorageId_GameCard, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if(total > 0) for(u32 i = 0; i < total; i++) arr.AddUInt(metas[i].metaRecord.titleId);
            ncmOpenContentMetaDatabase(FsStorageId_NandUser, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if(total > 0) for(u32 i = 0; i < total; i++) arr.AddUInt(metas[i].metaRecord.titleId);
            ncmOpenContentMetaDatabase(FsStorageId_SdCard, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if(total > 0) for(u32 i = 0; i < total; i++) arr.AddUInt(metas[i].metaRecord.titleId);
        }
        else js::ThrowError(Context, js::Error::CommonError, "Could not initialize \'ncm\' service");
        ncmExit();
        return js::Return::Variable;
    }

    js::Function getGameCartTitle(js::NativeContext Context)
    {
        js::FunctionHandler handler(Context);
        if(R_SUCCEEDED(ncmInitialize()))
        {
            NcmContentMetaDatabase *metadb = (NcmContentMetaDatabase*)malloc(sizeof(*metadb));
            NcmApplicationContentMetaKey *metas = (NcmApplicationContentMetaKey*)malloc(sizeof(NcmApplicationContentMetaKey) * 32);
            u32 total = 0;
            u32 written = 0;
            ncmOpenContentMetaDatabase(FsStorageId_GameCard, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if((total > 0) && (written > 0)) handler.ReturnUInt(metas[0].metaRecord.titleId);
            else handler.ReturnUInt(0);
        }
        else js::ThrowError(Context, js::Error::CommonError, "Could not initialize \'ncm\' service");
        ncmExit();
        return js::Return::Variable;
    }

    js::Function getNANDTitles(js::NativeContext Context)
    {
        js::FunctionHandler handler(Context);
        if(R_SUCCEEDED(ncmInitialize()))
        {
            js::Array arr(Context);
            handler.ReturnArray(arr);
            NcmContentMetaDatabase *metadb = (NcmContentMetaDatabase*)malloc(sizeof(*metadb));
            NcmApplicationContentMetaKey *metas = (NcmApplicationContentMetaKey*)malloc(sizeof(NcmApplicationContentMetaKey) * 32);
            u32 total = 0;
            u32 written = 0;
            ncmOpenContentMetaDatabase(FsStorageId_NandUser, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if(total > 0) for(u32 i = 0; i < total; i++) arr.AddUInt(metas[i].metaRecord.titleId);
        }
        else js::ThrowError(Context, js::Error::CommonError, "Could not initialize \'ncm\' service");
        ncmExit();
        return js::Return::Variable;
    }

    js::Function getSDTitles(js::NativeContext Context)
    {
        js::FunctionHandler handler(Context);
        if(R_SUCCEEDED(ncmInitialize()))
        {
            js::Array arr(Context);
            handler.ReturnArray(arr);
            NcmContentMetaDatabase *metadb = (NcmContentMetaDatabase*)malloc(sizeof(*metadb));
            NcmApplicationContentMetaKey *metas = (NcmApplicationContentMetaKey*)malloc(sizeof(NcmApplicationContentMetaKey) * 32);
            u32 total = 0;
            u32 written = 0;
            ncmOpenContentMetaDatabase(FsStorageId_SdCard, metadb);
            ncmContentMetaDatabaseListApplication(metadb, 0x80, metas, (sizeof(NcmApplicationContentMetaKey) * 32), &written, &total);
            if(total > 0) for(u32 i = 0; i < total; i++) arr.AddUInt(metas[i].metaRecord.titleId);
        }
        else js::ThrowError(Context, js::Error::CommonError, "Could not initialize \'ncm\' service");
        ncmExit();
        return js::Return::Variable;
    }

    js::Module Initialize()
    {
        js::Module nx("nx");
        nx.PushFunction("reboot", reboot);
        nx.PushFunction("shutDown", shutDown);
        nx.PushFunction("getTitles", getTitles);
        nx.PushFunction("getGameCartTitle", getGameCartTitle);
        nx.PushFunction("getNANDTitles", getNANDTitles);
        nx.PushFunction("getSDTitles", getSDTitles);
        return nx;
    }
}