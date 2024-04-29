# Platformio Multiple ESP Projects

I like prototyping, creating multiple independent projects for a single small idea is a waste, why not split up everything into several shared subprojects, like in CMake?
- https://community.platformio.org/t/best-way-to-use-the-same-project-to-build-multiple-different-apps/33074
- https://github.com/MacDada/DnWiFiDoorLock/blob/master/platformio.ini#L15

This was much easier to setup than a CMake project, all it took was scraping through the above project.
- An environment is a project with whatever name you want.
- You can make your own custom-named environments targeting whichever platform you want.
- Each environment can use its own libraries and build settings, so custom #proprocessor macros can be passed along to credential-requiring projects (pretty cool).
