@echo off

rem �t�@�C����
set FILE_NAME=
echo "�t�@�C��������͂��Ă�������"
set /P FILE_NAME=""

if exist %FILE_NAME%.h (
  echo �t�@�C�������݂��Ă����̂Ŏ��s���܂���ł���
  goto end
)

rem -------�w�b�_�t�@�C���̍쐬-------
  echo #pragma once >> %FILE_NAME%.h
  echo #include "Component.h" >> %FILE_NAME%.h
  echo #include "GameObject.h" >> %FILE_NAME%.h
  echo class sampleComponent : public ScriptBase { >> %FILE_NAME%.h
  echo public : >> %FILE_NAME%.h
  echo 	%FILE_NAME%() {}; >> %FILE_NAME%.h
  echo 	%FILE_NAME%(GameObject* gameObject); >> %FILE_NAME%.h
  echo 	~%FILE_NAME%() {}; >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	void Awake() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void Start() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void FirstUpdate() >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void Update() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void LastUpdate() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo } >> %FILE_NAME%.h

rem -------�\�[�X�t�@�C���̍쐬-------
  echo #include "%FILE_NAME%.h" >> %FILE_NAME%.c
  echo #include "GameObject.h" >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo %FILE_NAME%::%FILE_NAME%() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo %FILE_NAME%::~%FILE_NAME%() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::%FILE_NAME%(GameObject* _gameObject) { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::Awake() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::Start() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::FirstUpdate() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::Update() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
  echo %FILE_NAME%::LateStart() { >> %FILE_NAME%.c
  echo. >> %FILE_NAME%.c
  echo } >> %FILE_NAME%.c
timeout 60