#pragma once

#include <jni/functions.hpp>
#include <jni/class.hpp>
#include <jni/object.hpp>
#include <jni/type_signature.hpp>
#include <jni/tagging.hpp>

namespace jni
   {
    template < class TheTag, class >
    class Method;

    template < class TheTag, class R, class... Args >
    class Method< TheTag, R (Args...) >
       {
        private:
            jmethodID* method;

        public:
            using TagType = TheTag;
            using MethodType = R (Args...);
            using ReturnType = R;

            Method()
              : method(nullptr)
               {}

            Method(JNIEnv& env, const Class<TagType>& clazz, const char* name)
              : method(&GetMethodID(env, *clazz, name, TypeSignature<R (Args...)>()()))
               {}

            operator jmethodID&() const { return *method; }
       };
   }
