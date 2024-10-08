#include "transcript.hpp"
#include <algorithm>


void TranscriptRegistry::Add(const Transcript& transcript)
{
    transcripts_.push_back(transcript);
}

void TranscriptRegistry::RemoveById(const std::string& student_id)
{
    transcripts_.remove_if([&student_id](const Transcript& transcript){return transcript.student_id==student_id;});
}

std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string& student_id) const
{
    return std::find_if(transcripts_.begin(), transcripts_.end(), [&student_id](const Transcript& transcript){return transcript.student_id==student_id;});
}

std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(const std::string& course_name) const
{
    std::list<std::pair<std::string, size_t>> results;
    for(const auto& transcript:transcripts_)
    {
        for(const auto& grade_pair:transcript.grades)
        {
            if (grade_pair.first == course_name)
            {
                results.emplace_back(transcript.student_id, grade_pair.second);
            }
        }
    }
    return results;
}

const std::list<Transcript> TranscriptRegistry::GetTranscripts() const
{
    return transcripts_;
}